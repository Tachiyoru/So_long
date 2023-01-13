/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:12:53 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 15:26:25 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(t_data *data, char *file)
{
	int		fd;
	t_lst	**map_lst;

	if (!check_ber(file))
		return (map_checker_error(1));
	if (!pre_check_wrong_map(file))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(1, "Failed to open\n", 16), 0);
	map_lst = malloc(sizeof(t_lst *));
	if (!init_map(data, fd, map_lst))
		return (0);
	close (fd);
	save_map(&data->map, map_lst);
	free_lst(map_lst);
	if (!check_char(data))
		return (0);
	if (!wall_check(data->map))
		return (0);
	if (!do_you_know_the_way(data))
		return (0);
	return (1);
}

int	check_ber(char *file)
{
	int	fd;
	int	size;

	size = ft_strlen(file);
	fd = open(file, __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), false);
	else
	{
		if (file[size - 4] != '.' || file[size - 3] != 'b'
			|| file[size - 2] != 'e' || file[size - 1] != 'r')
			return (false);
	}
	return (true);
}

int	pre_check_wrong_map(char *file)
{
	int		fd;
	char	*buf;
	int		ret;
	int		i;

	i = 0;
	buf = ft_calloc(4, sizeof(*buf));
	if (!buf)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(buf), 0);
	ret = read(fd, buf, 3);
	if (ret < 0 || ret == 0)
		return (free(buf), 0);
	close(fd);
	while (buf[i])
	{
		if (buf[i] != '1')
			return (pre_check_wrong_map_error(buf, 1));
		i++;
	}
	return (free(buf), 1);
}

int	init_map(t_data *data, int fd, t_lst **maplst)
{
	size_t	size;

	data->map.collectible = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->map.ennemy = 0;
	data->monster = malloc(sizeof(t_mnster));
	size = 0;
	data->player.move_count = 0;
	data->player.collected = 0;
	data->map.lines = count_lines(fd, 1, maplst, size);
	if (data->map.lines < 3)
		return (lines_error(1));
	data->map.size_y = data->map.lines;
	data->map.size_x = ft_strlen2((*maplst)->mapline);
	if (data->map.size_x < 0)
		data->map.size_x = 0;
	if (data->map.size_x < 4)
		return (lines_error(2));
	data->map.map = ft_calloc(data->map.lines + 1, sizeof(char *));
	return (1);
}

int	count_lines(int fd, int lines, t_lst **maplst, size_t size)
{
	char	*line;
	t_lst	*tmp;
	t_lst	*new;
	t_lst	*last;

	line = get_next_line(fd);
	size = ft_strlen(line);
	tmp = new_node(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) != size)
			return (free(line), lines_error(3));
		if (line && ++lines)
		{
			new = new_node(line);
			last = ft_lstlast(tmp);
			last->next = new;
		}
	}
	free(line);
	*maplst = tmp;
	return (lines);
}
