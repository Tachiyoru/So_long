/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:37:15 by sleon             #+#    #+#             */
/*   Updated: 2022/12/10 14:53:21 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int key, void *param

int	key_capture(int key, t_data *data)
{
	(void)data;
	if (key == K_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		exit(1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (write(2, "Run as : ./so_long map\n", 24), EXIT_FAILURE);
	if (!check_map(&data, av[1]))
		return (false);
	return (0);
}

	// data->mlx_ptr = mlx_init();
	// if (data->mlx_ptr == NULL)
	// 	return (false);
	// data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
	// 		WINDOW_HEIGHT, "oui");
	// if (data->win_ptr == NULL)
	// 	return (false);
	// mlx_key_hook(data->win_ptr, key_capture, data);
	// mlx_loop(data->mlx_ptr);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	// free(data->mlx_ptr);
	// free(data);
