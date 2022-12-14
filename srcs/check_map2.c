/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:12:53 by sleon             #+#    #+#             */
/*   Updated: 2022/12/20 16:47:37 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	save_map(t_map *map, t_lst **maplst)
{
	int		i;
	int		column;
	int		row;
	int		size;
	t_lst	*save;

	i = -1;
	row = 0;
	column = -1;
	size = ft_strlen2((*maplst)->mapline) + 1;
	save = *maplst;
	while (save)
	{
		map->map[row] = ft_calloc(size, sizeof(char));
		if (!map->map[row])
			return (free (map->map));
		while (save->mapline[++i] != '\0' && save->mapline[i] != '\n')
			map->map[row][++column] = save->mapline[i];
		save = save->next;
		column = -1;
		i = -1;
		row++;
	}
	map->map[row] = NULL;
}

int	check_char(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (!good_char(data, data->map.map[i][j]))
				return (present_char_error(1));
		}
	}
	if (data->map.collectible < 1)
		return (present_char_error(2));
	if (data->map.player != 1)
		return (present_char_error(4));
	if (data->map.exit != 1)
		return (present_char_error(3));
	return (1);
}

int	good_char(t_data *data, char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'M')
		return (1);
	else if (c == 'C')
		data->map.collectible++;
	else if (c == 'E')
		data->map.exit++;
	else if (c == 'P')
		data->map.player++;
	else
		return (0);
	return (1);
}

int	wall_check(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (map.map[++i])
	{
		j = -1;
		if (i == 0 || map.map[i + 1] == NULL)
		{
			while (map.map[i][++j])
			{
				if (map.map[i][j] != '1')
					return (wall_checker_error(1));
			}
		}
		else
		{
			while (map.map[i][++j + 1])
				;
			if (map.map[i][0] != '1' && map.map[i][j] != '1')
				return (wall_checker_error(1));
		}
	}
	return (1);
}

int	do_you_know_the_way(t_data *data)
{
	int	**map_0;

	map_0 = init_map0(data);
	if (!map_0)
		return (0);
	if (!check_way(data, map_0, data->player.pos_y, data->player.pos_x))
		return (way_checking_error(1, map_0));
	fill_map_0(data, map_0);
	if (check_collectibles(data, map_0, data->player.pos_y, data->player.pos_x)
		!= data->map.collectible)
		return (way_checking_error(1, map_0));
	free_boolmap(map_0);
	return (1);
}
