/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:28:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 16:39:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"./libft/libft.h"
# include	"MLX/mlx.h"

# ifndef SIZE
#  define SIZE 60
# endif

typedef struct s_map	t_map;
typedef struct s_col	t_col;
typedef struct s_hero	t_hero;
typedef struct s_exit	t_exit;
typedef struct s_wall	t_wall;
typedef struct s_space	t_space;
typedef struct s_bg		t_bg;
typedef struct s_game	t_game;

struct s_map
{
	int					x;
	int					y;
	void				*win_ptr;
	void				*mlx_ptr;
	int					c;
	int					e;
	int					p;
	int					g;
	t_bg				*bg;
	t_game				*game;
};

struct s_bg
{
	t_space				*space;
	t_exit				*exit;
	t_wall				*wall;
};

struct s_game
{
	t_hero				*hero;
	t_col				*col;
};

struct s_col
{
	int					x;
	int					y;
	t_col				*next;
};

struct s_hero
{
	int					x;
	int					y;
	int					dir;
};

struct s_wall
{
	int					x;
	int					y;
	t_wall				*next;
};

struct s_space
{
	int					x;
	int					y;
	t_space				*next;
};

struct s_exit
{
	int					x;
	int					y;
	int					state;
};

// so_long.c
t_map					*ft_map_init(char *str);
// so_long_utils.c
int						ft_move(int key, t_map *map);
void					ft_grid(t_map *map);
void					ft_win(t_map *map);
// get_info.c
void					get_infos(t_map *map, int fd);
void					ft_check_params(int fd, t_map *map);
void					get_element(char *str, t_map *map, int y);
// ft_errors.c
void					error(char *msg);
void					error2(char *msg, t_map *map, char *str);
void					error3(char *msg, t_map *map);
// ft_strchr_so_long.c
void					ft_strchr_element(char *str, int y, char c, t_map *map);
int						ft_strchr_walls_h(char *str);
int						ft_strchr_walls_v(char *str, t_map *map);
// ft_free.c
void					ft_free_col(t_map *map);
void					ft_free_wall(t_map *map);
void					ft_free_space(t_map *map);
// ft_parsing.c
void					ft_collectibles(t_map *map, int x, int y, char *str);
void					ft_hero(t_map *map, int x, int y, char *str);
void					ft_exit(t_map *map, int x, int y, char *str);
void					ft_wall(t_map *map, int x, int y, char *str);
void					ft_space(t_map *map, int x, int y, char *str);
// ft_draw.c
void					ft_fill_square(t_map *map, int x, int y, int color);
void					ft_finder(t_map *map, int x, int y);
void					ft_find(t_map *map, int x, int y);
void					ft_draw(t_map *map);
// ft_moves.c
int 					ft_move_up(t_map *map);
int 					ft_move_left(t_map *map);
int 					ft_move_down(t_map *map);
int 					ft_move_right(t_map *map);

#endif
