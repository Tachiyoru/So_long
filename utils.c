/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:45 by sleon             #+#    #+#             */
/*   Updated: 2022/12/10 13:55:30 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
