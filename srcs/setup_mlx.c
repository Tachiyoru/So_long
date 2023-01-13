/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:43:04 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 14:04:00 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	setup_window(t_data *data)
{
	data->win_largeur = IMG_SIZE * data->map.size_y;
	data->win_l = IMG_SIZE * data->map.size_x;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free_map(data);
		return (false);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_l,
			data->win_largeur, "oui");
	if (data->win_ptr == NULL)
		return (false);
	if (!image_to_mlx(data))
		return (false);
	return (true);
}

int	image_to_mlx2(t_data	*data)
{
	int	img;

	img = 64;
	data->image.player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_DOWN,
			&img, &img);
	if (!data->image.player)
		return (0);
	data->image.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM,
			&img, &img);
	if (!data->image.item)
		return (0);
	data->image.monstre = mlx_xpm_file_to_image(data->mlx_ptr, MONSTRE,
			&img, &img);
	if (!data->image.item)
		return (0);
	return (1);
}

int	image_to_mlx(t_data	*data)
{
	int	img;

	img = 64;
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
	data->image.exit_o = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_O,
			&img, &img);
	if (!data->image.exit_o)
		return (0);
	if (!image_to_mlx2(data))
		return (0);
	return (1);
}
