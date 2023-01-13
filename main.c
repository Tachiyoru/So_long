/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:37:15 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 17:31:58 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_key(int k)
{
	if (k == K_A || k == K_LEFT)
		return (1);
	else if (k == K_W || k == K_UP)
		return (1);
	else if (k == K_S || k == K_DOWN)
		return (1);
	else if (k == K_D || k == K_RIGHT)
		return (1);
	return (0);
}

int	key_capture(int key, t_data *data)
{
	if (key == K_ESC)
	{
		close_img(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_map(data);
		exit(1);
	}
	if (is_key(key))
	{
		if (movements(data, key))
			mstr_move(data);
	}
	return (0);
}

int	crossbutton(t_data *data)
{
	close_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
		return (write(2, "Run as : ./so_long map\n", 24), EXIT_FAILURE);
	if (!check_map(&data, av[1]))
		return (2);
	if (!setup_window(&data))
		return (3);
	mapping(&data);
	salut(data);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (true);
}
