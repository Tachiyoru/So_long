/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:04:29 by sleon             #+#    #+#             */
/*   Updated: 2023/01/19 11:15:41 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	write_end(t_data *data, int a)
{
	char	*move;
	int		s;

	move = ft_itoa(data->player.move_count);
	s = ft_strlen2(move);
	if (a == 1)
	{
		write(1, "You won in [", 12);
		write(1, move, s);
		write(1, "] moves\n", 8);
		free(move);
		exit(0);
	}
	else if (a == 0)
	{
		write(1, "You lost in [", 13);
		write(1, move, s);
		write(1, "] moves\n", 8);
		free(move);
		exit(0);
	}
	else
		exit(1);
}

void	end_game(t_data *data, int a)
{
	close_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	free_map(data);
	write_end(data, a);
}

int	oui2(t_data *data, int y, int x)
{
	if (data->map.map[y][x] == 'M')
	{
		data->player.move_count++;
		end_game(data, 0);
	}
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
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->image.exit_o, data->player.exit_x * IMG_SIZE,
				data->player.exit_y * IMG_SIZE);
		}
	}
	else if (data->map.map[y][x] == 'Y')
	{
		data->player.move_count++;
		end_game(data, 1);
	}
	if (!oui2(data, y, x))
		return (0);
	return (1);
}

void	salut(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &mapping, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_capture, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&crossbutton, &data);
	mlx_loop(data.mlx_ptr);
}
