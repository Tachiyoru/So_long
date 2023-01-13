/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:04:29 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 12:48:31 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	movements(t_data *data, int key)
{
	int	y;
	int	x;
	int	size;

	size = 64;
	y = data->player.pos_y;
	x = data->player.pos_x;
	if (key == K_A || key == K_LEFT)
	{
		if (data->map.map[y][x - 1] != '1' && x > 0 &&
			x < data->win_largeur && oui(data, y, x - 1))
		{
			data->map.map[y][x] = '0';
			mlx_destroy_image(data->mlx_ptr, data->image.player);
			data->image.player = mlx_xpm_file_to_image(data->mlx_ptr,
					PLAYER_LEFT, &size, &size);
			if (data->image.player == 0)
				end_game(data, 2);
			return (1);
		}
	}
	if (!movements2(data, key, x, y))
		return (0);
	else
		return (1);
}

int	movements2(t_data *data, int key, int x, int y)
{
	int	size;

	size = 64;
	if (key == K_D || key == K_RIGHT)
	{
		if (data->map.map[y][x + 1] != '1' && x > 0 &&
			x < data->win_largeur && oui(data, y, x + 1))
		{
			data->map.map[y][x] = '0';
			mlx_destroy_image(data->mlx_ptr, data->image.player);
			data->image.player = mlx_xpm_file_to_image(data->mlx_ptr,
					PLAYER_RIGHT, &size, &size);
			if (data->image.player == 0)
				end_game(data, 2);
			return (1);
		}
	}
	if (!movements3(data, key, x, y))
		return (0);
	else
		return (1);
}

int	movements3(t_data *data, int key, int x, int y)
{
	int	size;

	size = 64;
	if (key == K_W || key == K_UP)
	{
		if (data->map.map[y - 1][x] != '1' && y > 0 &&
			y < data->win_l && oui(data, y - 1, x))
		{
			data->map.map[y][x] = '0';
			mlx_destroy_image(data->mlx_ptr, data->image.player);
			data->image.player = mlx_xpm_file_to_image(data->mlx_ptr,
					PLAYER_UP, &size, &size);
			if (data->image.player == 0)
				end_game(data, 2);
			return (1);
		}
	}
	if (!movements4(data, key, x, y))
		return (0);
	else
		return (1);
}

int	movements4(t_data *data, int key, int x, int y)
{
	int	size;

	size = 64;
	if (key == K_S || key == K_DOWN)
	{
		if (data->map.map[y + 1][x] != '1' && y > 0 &&
			y < data->win_l && oui(data, y + 1, x))
		{
			data->map.map[y][x] = '0';
			mlx_destroy_image(data->mlx_ptr, data->image.player);
			data->image.player = mlx_xpm_file_to_image(data->mlx_ptr,
					PLAYER_DOWN, &size, &size);
			if (data->image.player == 0)
				end_game(data, 2);
			return (1);
		}
	}
	return (0);
}
