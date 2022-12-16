/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:14:22 by sleon             #+#    #+#             */
/*   Updated: 2022/12/16 14:09:35 by sleon            ###   ########.fr       */
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

# define IMG_SIZE 100

# define GROUND			"image/ground.xpm"
# define PLAYER_DOWN	"image/player.xpm"
// # define PLAYER_UP		"image/player_up.xpm"
// # define PLAYER_LEFT	"image/player.xpm"
// # define PLAYER_RIGHT	"image/player_right.xpm"
# define ITEM			"image/item.xpm"
# define EXIT			"image/exit.xpm"
# define WALL			"image/wall.xpm"

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

typedef struct s_image
{
	void	*mlx_img;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*item;
}t_image;

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
	int		move_count;
}t_player;

typedef struct s_data
{
	int			win_largeur;
	int			win_longueur;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
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
void	salut(t_data data);
void	print_tab(t_data *data);

char	*ft_itoa(int n);
size_t	ft_strlen2(char *s);

//utils
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*new_node(char *content);
void	*ft_memset(void *a, int i, size_t count);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_puterr(char *str);

//gaming
int		crossbutton(t_data *data);
void	movements(t_data *data, int key);

//mapping
void	what_char(t_data *data, int i, int j);
int		mapping(t_data *data);

//setup_mlx
int		setup_window(t_data *data);
int		image_to_mlx(t_data	*data);

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
int		key_capture(int key, t_data *data);
int		main(int argc, char **argv);

#endif
