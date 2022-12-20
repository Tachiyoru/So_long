/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:11:32 by sleon             #+#    #+#             */
/*   Updated: 2022/12/20 15:00:22 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(char *str, long long nb, int j)
{
	j--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (j >= 0 && str[j] != '-')
	{
		str[j] = (nb % 10) + 48;
		nb /= 10;
		j--;
	}
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			j;
	char		*str;

	nb = (long long)n;
	j = 0;
	if (nb <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	str = ft_calloc(j + 1, 1);
	if (!str)
		return (NULL);
	str[j] = '\0';
	fill(str, nb, j);
	return (str);
}

size_t	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	free_lst(t_lst **map_lst)
{
	t_lst	*save;

	while (*map_lst)
	{
		save = *map_lst;
		(*map_lst) = (*map_lst)->next;
		free (save);
	}
	free(*map_lst);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map);
}
