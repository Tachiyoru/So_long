/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:14:22 by sleon             #+#    #+#             */
/*   Updated: 2023/01/19 11:49:28 by sleon            ###   ########.fr       */
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

# define IMG_SIZE 64

# define GROUND			"image/sol.xpm"
# define PLAYER_DOWN	"image/player_down.xpm"
# define PLAYER_UP		"image/player_up.xpm"
# define PLAYER_LEFT	"image/player_left.xpm"
# define PLAYER_RIGHT	"image/player_right.xpm"
# define ITEM			"image/chest_c.xpm"
# define EXIT			"image/exit_c.xpm"
# define EXIT_O			"image/exit_o.xpm"
# define WALL			"image/wall.xpm"
# define MONSTRE		"image/mechant.xpm"
# define MONSTRE2		"image/mechant2.xpm"

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
	void	*exit_o;
	void	*ground;
	void	*player;
	void	*monstre;
	void	*monstre2;
	void	*item;
}t_image;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collectible;
	int		ennemy;
	int		player;
	int		exit;
	int		lines;
	char	**map;

}t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		exit_x;
	int		exit_y;
	int		collected;
	int		open_exit;
	int		move_count;
	int		anim_frame;
}t_player;

typedef struct s_mnster
{
	int				mon_x;
	int				mon_y;
	char			last_pos;
	struct s_mnster	*next;
}t_mnster;

typedef struct s_data
{
	int			win_largeur;
	int			win_l;
	int			count;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
	t_map		map;
	t_player	player;
	t_mnster	*monster;
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
void	free_map(t_data *data);
void	free_lst(t_lst **map_lst);

int		mstr_move(t_data *data);
int		new_monster(t_data *data, int i, int j);

// close.c
void	close_img(t_data *data);
void	free_boolmap(int **bool_map);
void	free_tab(int **tab, int n);
void	free_tab_char(char **tab, int n);

//utils
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*new_node(char *content);
void	*ft_memset(void *a, int i, size_t count);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_puterr(char *str);

//gaming_mov
int		movements(t_data *data, int key);
int		movements2(t_data *data, int key, int x, int y);
int		movements3(t_data *data, int key, int x, int y);
int		movements4(t_data *data, int key, int x, int y);

//gaming
int		crossbutton(t_data *data);
void	end_game(t_data *data, int a);
int		oui(t_data *data, int y, int x);

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
int		way_checking_error(int err, int **map_0);

//check_map2
void	save_map(t_map *map, t_lst **maplst);
int		check_char(t_data *data);
int		good_char(t_data *data, char c);
int		do_you_know_the_way(t_data *data);

//check_map
int		check_map(t_data *data, char *file);
int		check_ber(char *file);
int		check_wall(t_lst **maplst, int s);
int		init_map(t_data *data, int fd, t_lst **maplst);
int		count_lines(int fd, int lines, t_lst **maplst, size_t size);

//error
int		map_checker_error(int err);
int		lines_error(int err);
int		present_char_error(int err);
int		wall_checker_error(int err);

//main
int		key_capture(int key, t_data *data);
int		main(int argc, char **argv);

#endif
