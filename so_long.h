/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:28:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/20 16:37:45 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"./libft/libft.h"
# include	"MLX/mlx.h"

# ifndef SIZE
#  define SIZE 50
# endif

typedef struct s_map	t_map;
typedef struct s_col	t_col;

struct s_map
{
	int					x;
	int					y;
	void				*win_ptr;
	void				*mlx_ptr;
	int					c;
	t_col				*col;
	int					e;
	int					e_x;
	int					e_y;
	int					p;
	int					p_x;
	int					p_y;
};

struct s_col
{
	int					x;
	int					y;
	t_col				*next;
};

// so_long.c
t_map					*ft_map_init(char *str);
// so_long_utils.c
int						ft_move(int key, t_map *param);
// get_info.c
void					get_infos(t_map *map, int fd);
void					ft_check_params(int fd, t_map *map);
void					get_element(char *str, t_map *map, int y);
// ft_errors.c
void					error(char *msg);
void					error2(char *msg, t_map *map, char *str, int i);
void					error3(char *msg, t_map *map, int i);
// ft_strchr_so_long.c
void					ft_strchr_element(char *str, int y, char c, t_map *map);
int						ft_strchr_walls_h(char *str);
int						ft_strchr_walls_v(char *str, t_map *map);
// ft_free.c
void					ft_free(t_map *map);
// ft_draw.c

#endif
