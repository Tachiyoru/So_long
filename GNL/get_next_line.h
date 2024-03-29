/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:37:05 by sleon             #+#    #+#             */
/*   Updated: 2023/01/14 16:11:31 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../so_long.h"

# define BUFFER_SIZE 10

char		*get_next_line(int fd, int reset);
char		*ft_read_line(int fd, char *line);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *line, char *buff);
char		*ft_line_to_buff(char *line);
char		*ft_read_new_line(char *line);

#endif
