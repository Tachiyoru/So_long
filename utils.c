/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:45 by sleon             #+#    #+#             */
/*   Updated: 2022/12/10 16:35:35 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_lst	*new_node(char *content)
{
	t_lst	*node;
	int		i;

	i = -1;
	node = malloc(sizeof(t_lst));
	node->mapline = ft_calloc(ft_strlen(content), sizeof(char));
	if (!node)
		return (0);
	while (content[++i])
		node->mapline[i] = content[i];
	node->next = NULL;
	return (node);
}

void	*ft_memset(void *a, int i, size_t count)
{
	size_t			s;
	unsigned char	*ptr;

	s = 0;
	ptr = (unsigned char *)a;
	while (s < count)
		ptr[s++] = (unsigned char)i;
	return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, nmemb * size);
	return (mem);
}

void	ft_puterr(char *str)
{
	write(2, str, ft_strlen(str));
}
