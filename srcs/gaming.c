/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:04:29 by sleon             #+#    #+#             */
/*   Updated: 2022/12/15 15:24:56 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	oui(t_data *data, int y, int x)
{
	if (data->map.map[y][x] == 'C')
	{
		data->player.collected++;
		data->player.move_count++;
		data->map.map[y][x] = 'P';
	}
	if (data->map.map[y][x] == 'E')
	{
		if (data->player.collected == data->map.collectible)
			data->player.move_count++;
			// end_game(data);
		return (0);
	}
	if (data->map.map[y][x] == 0)
	{
		data->player.move_count++;
		data->map.map[y][x] = 'P';
	}
	return (1);
}

void	print_tab(t_data *data)
{
	int	i = -1;
	int	j = -1;
	while (data->map.map[++i])
	{
		while (data->map.map[i][++j])
			dprintf(STDERR_FILENO, "%c", data->map.map[i][j]);
		j = -1;
		dprintf(STDERR_FILENO, "\n");
	}
	dprintf(STDERR_FILENO, "%d", data->player.pos_y);
	dprintf(STDERR_FILENO, "%d", data->player.pos_x);
}

void	salut(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &mapping, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_capture, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&crossbutton, &data);
	mlx_loop(data.mlx_ptr);
}

void	movements(t_data *data, int key)
{
	int	y;
	int	x;

	y = data->player.pos_y;
	x = data->player.pos_x;
	print_tab(data);
	if (key == K_A)
	{
		if (data->map.map[y][x - 1] != 1 && x > 0 &&
			x < data->win_largeur && oui(data, y, x - 1))
				data->map.map[y][x] = 0;
	}
	else if (key == K_W)
	{
		if (data->map.map[y - 1][x] != 1 && y > 0 &&
			y < data->win_longueur && oui(data, y - 1, x))
				data->map.map[y][x] = 0;
	}
	else if (key == K_S)
	{
		if (data->map.map[y + 1][x] != 1 && y > 0 &&
			y < data->win_longueur && oui(data, y + 1, x))
				data->map.map[y][x] = 0;
	}
	else if (key == K_D)
	{
		if (data->map.map[y][x + 1] != 1 && x > 0 &&
			x < data->win_largeur && oui(data, y, x + 1))
				data->map.map[y][x] = 0;
	}
}
