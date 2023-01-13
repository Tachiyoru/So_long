/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:12:24 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 17:37:42 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_img(t_data *data)
{
	if (data->image.exit)
		mlx_destroy_image(data->mlx_ptr, data->image.exit);
	if (data->image.item)
		mlx_destroy_image(data->mlx_ptr, data->image.item);
	if (data->image.player)
		mlx_destroy_image(data->mlx_ptr, data->image.player);
	if (data->image.ground)
		mlx_destroy_image(data->mlx_ptr, data->image.ground);
	if (data->image.wall)
		mlx_destroy_image(data->mlx_ptr, data->image.wall);
	if (data->image.exit_o)
		mlx_destroy_image(data->mlx_ptr, data->image.exit_o);
	if (data->image.monstre)
		mlx_destroy_image(data->mlx_ptr, data->image.monstre);
	if (data->image.monstre2)
		mlx_destroy_image(data->mlx_ptr, data->image.monstre2);
}

void	free_boolmap(int **bool_map)
{
	int	i;

	i = -1;
	while (bool_map[++i])
		free(bool_map[i]);
	free(bool_map);
	return ;
}

void	free_tab(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab_char(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
