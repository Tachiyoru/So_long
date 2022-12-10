/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_way_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:22:45 by sleon             #+#    #+#             */
/*   Updated: 2022/12/10 13:53:27 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**init_map0(t_data *data)
{
	int	**map_0;
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (data->map.map[++i])
		;
	while (data->map.map[i - 1][++j])
		;
	map_0 = ft_calloc(i, sizeof(int *));
	if (!map_0)
		return (NULL);
	i = -1;
	while (data->map.map[++i])
	{
		map_0[i] = ft_calloc(j, sizeof(int));
		if (!map_0[i])
			return (NULL);
	}
	fill_map_0(data, map_0);
	return (map_0);
}

void	fill_map_0(t_data *data, int **map_0)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == '1')
				map_0[i][j] = 1;
			else if (data->map.map[i][j] == 'P')
			{
				data->player.pos_x = j;
				data->player.pos_y = i;
			}
			else
				map_0[i][j] = 0;
		}
	}
}

int	check_way(t_data *data, int **map_0, int x, int y)
{
	map_0[x][y] = 1;
	if (data->map.map[x + 1][y] == 'E' || data->map.map[x - 1][y] == 'E'
		|| data->map.map[x][y + 1] == 'E' || data->map.map[x][y - 1] == 'E')
		return (1);
	if ((map_0[x + 1][y] == 'E' && check_way(data, map_0, x, y))
		|| (map_0[x - 1][y] == 'E' && check_way(data, map_0, x, y))
		|| (map_0[x][y + 1] == 'E' && check_way(data, map_0, x, y))
		|| (map_0[x][y - 1] == 'E' && check_way(data, map_0, x, y)))
		return (1);
	return (0);
}

int	check_collectibles(t_data *data, int **bool_map, int x, int y)
{
	int	cnt;

	cnt = 0;
	if (bool_map[y][x] == 1)
		return (0);
	bool_map[y][x] = 1;
	if (data->map.map[y][x] == 'C')
		cnt++;
	if (bool_map[y + 1][x] == 0)
		cnt += check_collectibles(data, bool_map, y + 1, x);
	if (bool_map[y - 1][x] == 0)
		cnt += check_collectibles(data, bool_map, y - 1, x);
	if (bool_map[y][x + 1] == 0)
		cnt += check_collectibles(data, bool_map, y, x + 1);
	if (bool_map[y][x - 1] == 0)
		cnt += check_collectibles(data, bool_map, y, x - 1);
	return (cnt);
}

int	way_checking_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("All exits and collectibles must be reachables\n");
	return (0);
}
