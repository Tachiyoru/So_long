/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:43:04 by sleon             #+#    #+#             */
/*   Updated: 2022/12/14 14:27:13 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	setup_window(t_data *data)
{
	data->win_largeur = IMG_SIZE * data->map.size_y;
	data->win_longueur = IMG_SIZE * data->map.size_x;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (false);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_longueur,
			data->win_largeur, "oui");
	if (data->win_ptr == NULL)
		return (false);
	if (!image_to_mlx(data))
		return (false);
	return (true);
}
// free la sturc en cas d'erreur

int	image_to_mlx(t_data	*data)
{
	int	img;

	img = 100;
	data->image.ground = mlx_xpm_file_to_image(data->mlx_ptr, GROUND,
			&img, &img);
	if (!data->image.ground)
		return (0);
	data->image.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&img, &img);
	if (!data->image.wall)
		return (0);
	data->image.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&img, &img);
	if (!data->image.exit)
		return (0);
	data->image.player_down = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_DOWN,
			&img, &img);
	if (!data->image.player_down)
		return (0);
	data->image.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM,
			&img, &img);
	if (!data->image.item)
		return (0);
	return (1);
}

	// data->image.player_up = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_UP,
	// 		IMG_SIZE, IMG_SIZE);
	// if (!data->image.player_up)
	// 	return (0);
	// data->image.player_left = mlx_xpm_file_to_image(data->mlx_ptr,
	//		PLAYER_LEFT, IMG_SIZE, IMG_SIZE);
	// if (!data->image.player_left)
	// 	return (0);
	// data->image.player_right = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		PLAYER_RIGHT, IMG_SIZE, IMG_SIZE);
	// if (!data->image.player_right)
	// 	return (0);
