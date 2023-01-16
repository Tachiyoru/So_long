/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:15:54 by sleon             #+#    #+#             */
/*   Updated: 2023/01/16 12:09:36 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_checker_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("Map has to be a .ber file\n");
	return (0);
}

int	lines_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("Map need atleast 3 lines\n");
	if (err == 2)
		ft_puterr("Need atleast 3 columns\n");
	if (err == 3)
		ft_puterr("All horizontal lanes needs same lenght\n");
	return (0);
}

int	present_char_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("You can only use 0, 1, C, E and P char and M in bonus\n");
	if (err == 2)
		ft_puterr("You must place 1 or more collectibles\n");
	if (err == 3)
		ft_puterr("You must place one, and only one exit\n");
	if (err == 4)
		ft_puterr("You must place one, and only one start\n");
	return (0);
}

int	wall_checker_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("All map borders must be walls\n");
	return (0);
}
