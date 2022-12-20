/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:16:12 by sleon             #+#    #+#             */
/*   Updated: 2022/12/20 14:48:23 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mapping(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
			what_char(data, i, j);
	}
	return (1);
}

void	what_char(t_data *data, int i, int j)
{
	char	*moves;

	moves = ft_itoa(data->player.move_count);
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.wall,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.ground, j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.monstre, j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.exit,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'Y')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.exit_o, j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.player, j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.item,
			j * IMG_SIZE, i * IMG_SIZE);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 30, 0xFEFEFF, moves);
	free(moves);
}
