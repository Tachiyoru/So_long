/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:14:22 by sleon             #+#    #+#             */
/*   Updated: 2022/12/13 11:15:55 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "GNL/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define K_ESC 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_A			97
# define K_W			119
# define K_S			115
# define K_D			100

/* ***************************/
/* 			STRUCTS			 */
/* ***************************/

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collectible;
	int		player;
	int		exit;
	int		lines;
	char	**map;

}t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		collected;
	int		open_exit;
}t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;

}t_data;

typedef struct s_lst
{
	char			*mapline;
	struct s_lst	*next;
}t_lst;

/* ***************************/
/* 			FUNCTIONS		 */
/* ***************************/

//utils
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*new_node(char *content);
void	*ft_memset(void *a, int i, size_t count);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_puterr(char *str);

//map_way_ok
int		**init_map0(t_data *data);
void	fill_map_0(t_data *data, int **map_0);
int		check_way(t_data *data, int **map_0, int x, int y);
int		check_collectibles(t_data *data, int **bool_map, int x, int y);
int		way_checking_error(int err);

//check_map2
void	save_map(t_map *map, t_lst **maplst);
int		check_char(t_map map);
int		good_char(t_map *map, char c);
int		wall_check(t_map map);
int		do_you_know_the_way(t_data *data);

//check_map
int		check_map(t_data *data, char *file);
int		check_ber(char *file);
int		pre_check_wrong_map(char *file);
int		init_map(t_data *data, int fd, t_lst **maplst);
int		count_lines(int fd, int lines, t_lst **maplst, size_t size);

//error
int		map_checker_error(int err);
int		lines_error(int err);
int		present_char_error(int err);
int		wall_checker_error(int err);
int		pre_check_wrong_map_error(char *buf, int err);

//main
int		main(int argc, char **argv);

#endif
