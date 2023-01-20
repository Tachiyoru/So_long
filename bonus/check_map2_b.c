/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:12:53 by sleon             #+#    #+#             */
/*   Updated: 2023/01/19 12:07:26 by sleon            ###   ########.fr       */
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
			return (free_tab_char(map->map, row));
		while (save->mapline[++i] != '\0' && save->mapline[i] != '\n')
			map->map[row][++column] = save->mapline[i];
		save = save->next;
		column = -1;
		i = -1;
		row++;
	}
	map->map[row] = NULL;
}

int	good_char2(t_data *data, char c, int i, int j)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'M')
	{
		if (!new_monster(data, i, j))
			return (0);
	}
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
			if (!good_char2(data, data->map.map[i][j], i, j))
				return (free_map(data), present_char_error(1));
		}
	}
	if (data->map.collectible < 1)
		return (free_map(data), present_char_error(2));
	if (data->map.player != 1)
		return (free_map(data), present_char_error(4));
	if (data->map.exit != 1)
		return (free_map(data), present_char_error(3));
	return (1);
}

int	check_wall(t_lst **maplst, int s)
{
	int		j;
	t_lst	*tmp;

	tmp = *maplst;
	s = ft_strlen2(tmp->mapline) - 1;
	j = -1;
	while (++j < s)
	{
		if (tmp->mapline[j] != '1')
			return (0);
	}
	tmp = tmp->next;
	while (tmp->next)
	{
		if (tmp->mapline[0] != '1' || tmp->mapline[s] != '1')
			return (0);
		tmp = tmp->next;
	}
	j = -1;
	while (++j < s)
	{
		if (tmp->mapline[j] != '1')
			return (0);
	}
	return (1);
}

int	do_you_know_the_way(t_data *data)
{
	int	**map_0;

	map_0 = init_map0(data);
	if (!map_0)
		return (free_map(data), 0);
	if (!check_way(data, map_0, data->player.pos_y, data->player.pos_x))
		return (free_map(data), way_checking_error(1, map_0));
	fill_map_0(data, map_0);
	if (check_collectibles(data, map_0, data->player.pos_y, data->player.pos_x)
		!= data->map.collectible)
		return (free_map(data), way_checking_error(1, map_0));
	free_boolmap(map_0);
	return (1);
}
