/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:38:23 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 17:03:09 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mstr_move_up(t_map *map, t_mnster *mon)
{
	if (map->map[mon->mon_y - 1][mon->mon_x] != '1'
		&& map->map[mon->mon_y - 1][mon->mon_x] != 'M'
		&& map->map[mon->mon_y - 1][mon->mon_x] != 'E'
		&& map->map[mon->mon_y - 1][mon->mon_x] != 'Y')
	{
		if (map->map[mon->mon_y - 1][mon->mon_x] == 'P')
			return (0);
		else if (mon->last_pos == 'C')
			map->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map->map[mon->mon_y - 1][mon->mon_x];
		map->map[mon->mon_y - 1][mon->mon_x] = 'M';
		mon->mon_y = mon->mon_y - 1;
		return (1);
	}
	return (0);
}

int	mstr_move_left(t_map *map, t_mnster *mon)
{
	if (map->map[mon->mon_y][mon->mon_x - 1] != '1'
		&& map->map[mon->mon_y][mon->mon_x - 1] != 'M'
		&& map->map[mon->mon_y][mon->mon_x - 1] != 'Y'
		&& map->map[mon->mon_y][mon->mon_x - 1] != 'E')
	{
		if (map->map[mon->mon_y][mon->mon_x - 1] == 'P')
			return (0);
		else if (mon->last_pos == 'C')
			map->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map->map[mon->mon_y][mon->mon_x - 1];
		map->map[mon->mon_y][mon->mon_x - 1] = 'M';
		mon->mon_x = mon->mon_x - 1;
		return (1);
	}
	return (0);
}

int	mstr_move_right(t_map *map, t_mnster *mon)
{
	if (map->map[mon->mon_y][mon->mon_x + 1] != '1'
		&& map->map[mon->mon_y][mon->mon_x + 1] != 'M'
		&& map->map[mon->mon_y][mon->mon_x + 1] != 'Y'
		&& map->map[mon->mon_y][mon->mon_x + 1] != 'E')
	{
		if (map->map[mon->mon_y][mon->mon_x + 1] == 'P')
			return (0);
		else if (mon->last_pos == 'C')
			map->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map->map[mon->mon_y][mon->mon_x + 1];
		map->map[mon->mon_y][mon->mon_x + 1] = 'M';
		mon->mon_x = mon->mon_x + 1;
		return (1);
	}
	return (0);
}

int	mstr_move_down(t_map *map, t_mnster *mon)
{
	if (map->map[mon->mon_y + 1][mon->mon_x] != '1'
		&& map->map[mon->mon_y + 1][mon->mon_x] != 'M'
		&& map->map[mon->mon_y + 1][mon->mon_x] != 'Y'
		&& map->map[mon->mon_y + 1][mon->mon_x] != 'E')
	{
		if (map->map[mon->mon_y + 1][mon->mon_x] == 'P')
			return (0);
		else if (mon->last_pos == 'C')
			map->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map->map[mon->mon_y + 1][mon->mon_x];
		map->map[mon->mon_y + 1][mon->mon_x] = 'M';
		mon->mon_y = mon->mon_y + 1;
		return (1);
	}
	return (0);
}

int	mstr_move(t_data *data)
{
	int			rd;
	int			i;
	t_mnster	*tmp;

	i = 0;
	tmp = data->monster;
	while (i < data->map.ennemy)
	{
		rd = rand() % 4;
		if (rd == 0)
			mstr_move_up(&data->map, data->monster);
		else if (rd == 1)
			mstr_move_left(&data->map, data->monster);
		else if (rd == 2)
			mstr_move_right(&data->map, data->monster);
		else if (rd == 3)
			mstr_move_down(&data->map, data->monster);
		i++;
		if (data->monster->next)
			data->monster = data->monster->next;
	}
	data->monster = tmp;
	return (0);
}
