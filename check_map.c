/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:12:53 by sleon             #+#    #+#             */
/*   Updated: 2022/12/10 15:45:27 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_data *data, char *file)
{
	int	fd;

	if (!check_ber(file))
		return (map_checker_error(1));
	if (!pre_check_wrong_map(file))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(1, "Failed to open\n", 16), 0);
	if (!init_map(data, fd))
		return (0);
	close (fd);
	fd = open(file, O_RDONLY);
	save_map(&data->map, fd);
	close(fd);
	if (!check_char(data->map))
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
		return (0);
	ret = read(fd, buf, 3);
	if (ret < 0 || ret == 0)
		return (0);
	close(fd);
	while (buf[i])
	{
		if (buf[i] != '1')
			return (pre_check_wrong_map_error(buf, 1));
		i++;
	}
	return (free(buf), 1);
}

int	init_map(t_data *data, int fd)
{
	data->map.collectible = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->map.lines = count_lines(fd, data->map.lines);
	if (data->map.lines == 0)
		return (0);
	data->map.map = ft_calloc(data->map.lines + 1, sizeof(char *));
	return (1);
}

int	count_lines(int fd, int lines)
{
	char	*line;
	size_t	size;
	int		i;

	i = 0;
	lines = 0;
	line = get_next_line(fd);
	size = ft_strlen(line);
	if (size <= 3)
		return (lines_error(2), 0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) != size)
			return (lines_error(3), 0);
		lines++;
		i++;
	}
	if (i <= 3)
		return (lines_error(1), 0);
	return (lines);
}
