/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:28:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 14:35:01 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"./libft/libft.h"
# include	"MLX/mlx.h"

typedef struct s_map	t_map;

struct s_map
{
	int					x;
	int					y;
	void				*win_ptr;
	void				*mlx_ptr;
};

// so_long.c
t_map					*ft_map_init(char *str);
// so_long_utils.c
int						ft_move(int key, t_map *param);
// get_info.c
int						get_dim(int fd, int a);

#endif
