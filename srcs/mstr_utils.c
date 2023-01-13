/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mstr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:27:59 by sleon             #+#    #+#             */
/*   Updated: 2023/01/13 14:55:38 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mnster	*ft_2lstlast(t_mnster *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	new_monster(t_data *data, int i, int j)
{
	t_mnster	*last;
	t_mnster	*tmp;

	data->map.ennemy++;
	if (data->map.ennemy == 1)
	{
		data->monster->mon_y = i;
		data->monster->mon_x = j;
		data->monster->last_pos = 'a';
		data->monster->next = NULL;
	}
	else
	{
		tmp = malloc(sizeof(t_mnster));
		last = ft_2lstlast(data->monster);
		tmp->mon_y = i;
		tmp->mon_x = j;
		tmp->last_pos = 'a';
		tmp->next = NULL;
		last->next = tmp;
	}
}
