/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:04:29 by sleon             #+#    #+#             */
/*   Updated: 2022/12/19 17:00:48 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_do_sync(data->mlx_ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 30, 0xFEFEFF, "movewfdw");
	mlx_loop(data->mlx_ptr);
}

int	oui(t_data *data, int y, int x)
{
	if (data->map.map[y][x] == 'C')
	{
		data->player.collected++;
		data->player.move_count++;
		data->map.map[y][x] = 'P';
		data->player.pos_y = y;
		data->player.pos_x = x;
		if (data->map.collectible == data->player.collected)
		{
			data->map.map[data->player.exit_y][data->player.exit_x] = 'Y';
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.exit_o,
				data->player.exit_x * IMG_SIZE, data->player.exit_y * IMG_SIZE);
		}
	}
	else if (data->map.map[y][x] == 'Y')
		end_game(data);
	else if (data->map.map[y][x] == 'E')
		return (0);
	else if (data->map.map[y][x] == '0')
	{
		data->player.move_count++;
		data->map.map[y][x] = 'P';
		data->player.pos_y = y;
		data->player.pos_x = x;
	}
	return (1);
}

// void	print_tab(t_data *data)
// {
// 	int	i = -1;
// 	int	j = -1;
// 	while (data->map.map[++i])
// 	{
// 		while (data->map.map[i][++j])
// 			dprintf(STDERR_FILENO, "%c", data->map.map[i][j]);
// 		j = -1;
// 		dprintf(STDERR_FILENO, "\n");
// 	}
// }

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
	if (key == K_A || key == K_LEFT)
	{
		if (data->map.map[y][x - 1] != '1' && x > 0 &&
			x < data->win_largeur && oui(data, y, x - 1))
				data->map.map[y][x] = '0';
	}
	else if (key == K_W || key == K_UP)
	{
		if (data->map.map[y - 1][x] != '1' && y > 0 &&
			y < data->win_longueur && oui(data, y - 1, x))
				data->map.map[y][x] = '0';
	}
	else if (key == K_S || key == K_DOWN)
	{
		if (data->map.map[y + 1][x] != '1' && y > 0 &&
			y < data->win_longueur && oui(data, y + 1, x))
				data->map.map[y][x] = '0';
	}
	else if (key == K_D || key == K_RIGHT)
	{
		if (data->map.map[y][x + 1] != '1' && x > 0 &&
			x < data->win_largeur && oui(data, y, x + 1))
				data->map.map[y][x] = '0';
	}
}
