/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:28:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/17 15:47:25 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"./libft/libft.h"
# include	"./MLX/mlx.h"

# ifndef SIZE
#  define SIZE 50
# endif

typedef struct s_map	t_map;
typedef struct s_col	t_col;
typedef struct s_hero	t_hero;
typedef struct s_exit	t_exit;
typedef struct s_wall	t_wall;
typedef struct s_space	t_space;
typedef struct s_trap	t_trap;
typedef struct s_bg		t_bg;
typedef struct s_game	t_game;
typedef struct s_images	t_images;

struct s_map
{
	int					x;
	int					y;
	void				*win_ptr;
	void				*mlx_ptr;
	int					c;
	int					c_copy;
	int					e;
	int					p;
	int					g;
	char				*map;
	t_images			*images;
	t_bg				*bg;
	t_game				*game;
	char				*t;
};

struct s_images
{
	void				*hero;
	void				*exit;
	void				*wall;
	void				*space;
	void				*col;
	void				*trap;
};

struct s_bg
{
	t_space				*space;
	t_exit				*exit;
	t_wall				*wall;
	t_trap				*trap;
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
	int					state;
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

struct s_trap
{
	int					x;
	int					y;
	t_trap				*next;
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
int						ft_move(int key, t_map *map, unsigned int key_press);
void					ft_end(t_map *map, unsigned int key_press, int i);
void					images_init(t_map *map);
void					ft_black(t_map *map);
// so_long_utils_bonus.c
int						deal_key_end(int key, t_map *map);
// get_info.c
void					get_infos(t_map *map, int fd);
void					ft_check_params(int fd, t_map *map);
void					get_element(char *str, t_map *map, int y);
// ft_errors.c
void					error(int i);
void					error2(char *msg, t_map *map, char *str);
void					error3(char *msg, t_map *map);
// ft_strchr_so_long.c
void					ft_strchr_element(char *str, int y, char c, t_map *map);
int						ft_strchr_walls_h(char *str);
int						ft_strchr_walls_v(char *str, t_map *map);
// ft_success.c
void					ft_success(t_map *map);
// ft_free.c
void					ft_free_trap(t_map *map);
void					ft_free_col(t_map *map);
void					ft_free_wall(t_map *map);
void					ft_free_space(t_map *map);
int						ft_free_images(t_map *map);
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
void					ft_redraw_exit(t_map *map, int x, int y);
// ft_moves.c
int						ft_move_up(t_map *map, unsigned int key_press);
int						ft_move_left(t_map *map, unsigned int key_press);
int						ft_move_down(t_map *map, unsigned int key_press);
int						ft_move_right(t_map *map, unsigned int key_press);
// ft_moves.utils.c
void					ft_redraw_game(t_map *map, int i, int x, int y);
void					ft_redraw_end(t_map *map, int x, int y, int i);
int						ft_collect(t_map *map, int x, int y, int i);
// ft_images.c
char					*ft_open_image(char *file);
// ft_menu.c
void					ft_draw_menu(t_map *map);
int						deal_key_menu(int key, t_map *map);
// ft_others.c
void					ft_trap(t_map *map, int x, int y, char *str);
int						ft_close_click(int keycode, t_game *game);
int						check_map(char *str);
int						ft_check_path(t_map *map);
void					ft_grid(t_map *map, int i);
// bonus/ft_lose.c
int						ft_lose(t_map *map, int x, int y, int i);

#endif
