/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:37:15 by sleon             #+#    #+#             */
/*   Updated: 2022/12/14 14:59:02 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_capture(int key, t_data *data)
{
	if (key == K_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else if (ft_strchr2("wasd", keysym))
		move_player(data, keysym);
	return (0);
}

int	crossbutton(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (write(2, "Run as : ./so_long map\n", 24), EXIT_FAILURE);
	if (!check_map(&data, av[1]))
		return (false);
	if (!setup_window(&data))
		return (false);
	gaming(&data);
	mlx_loop_hook(data.mlx_ptr, &gaming, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_capture, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&crossbutton, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (true);
}
	// ft_destroy_img(&data);
