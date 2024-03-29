/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_way_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:22:45 by sleon             #+#    #+#             */
/*   Updated: 2023/01/14 14:56:07 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**init_map0(t_data *data)
{
	int	**map_0;
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (data->map.map[++i])
		;
	while (data->map.map[0][++j])
		;
	map_0 = ft_calloc(i + 1, sizeof(int *));
	if (!map_0)
		return (NULL);
	map_0[i] = 0;
	i = -1;
	while (data->map.map[++i])
	{
		map_0[i] = ft_calloc(j + 1, sizeof(int));
		if (!map_0[i])
			return (free_tab(map_0, i), NULL);
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
				map_0[i][j] = 0;
			if (data->map.map[i][j] == '1')
				map_0[i][j] = 1;
			else if (data->map.map[i][j] == 'P')
			{
				data->player.pos_y = i;
				data->player.pos_x = j;
			}
			else if (data->map.map[i][j] == 'E')
			{
				data->player.exit_y = i;
				data->player.exit_x = j;
			}
		}
		map_0[i][j] = 0;
	}
}

int	check_way(t_data *data, int **map_0, int y, int x)
{
	if (map_0[y][x] == 1)
		return (0);
	map_0[y][x] = 1;
	if (data->map.map[y + 1][x] == 'E' || data->map.map[y - 1][x] == 'E'
		|| data->map.map[y][x + 1] == 'E' || data->map.map[y][x - 1] == 'E')
		return (1);
	if ((map_0[y + 1][x] == 0 && check_way(data, map_0, y + 1, x))
		|| (map_0[y - 1][x] == 0 && check_way(data, map_0, y - 1, x))
		|| (map_0[y][x + 1] == 0 && check_way(data, map_0, y, x + 1))
		|| (map_0[y][x - 1] == 0 && check_way(data, map_0, y, x - 1)))
		return (1);
	return (0);
}

int	check_collectibles(t_data *data, int **bool_map, int y, int x)
{
	int	cnt;

	cnt = 0;
	if (bool_map[y][x] == 1 || data->map.map[y][x] == 'E')
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

int	way_checking_error(int err, int **map_0)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("All exits and collectibles must be reachables\n");
	free_boolmap(map_0);
	return (0);
}
