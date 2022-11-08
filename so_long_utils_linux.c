/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/08 13:29:54 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, t_map *map, unsigned int key_press)
{
	if (key == 122 || key == 65362)
		return (ft_move_up(map, key_press));
	else if (key == 113 || key == 65361)
		return (ft_move_left(map, key_press));
	else if (key == 115 || key == 65364)
		return (ft_move_down(map, key_press));
	else if (key == 100 || key == 65363)
		return (ft_move_right(map, key_press));
	else if (key == 65307)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	images_init(t_map *map)
{
	int	size;

	size = 1 * SIZE;
	map->images->hero = mlx_new_image(map->mlx_ptr, size, size);
	map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/So_long/Hero_3.xpm", &size, &size);
	map->images->exit = mlx_new_image(map->mlx_ptr, size, size);
	map->images->exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/So_long/Exit_closed.xpm", &size, &size);
	map->images->wall = mlx_new_image(map->mlx_ptr, size, size);
	map->images->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/So_long/Wall.xpm", &size, &size);
	map->images->space = mlx_new_image(map->mlx_ptr, size, size);
	map->images->space = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/So_long/Ground.xpm", &size, &size);
	map->images->col = mlx_new_image(map->mlx_ptr, size, size);
	map->images->col = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/So_long/Col.xpm", &size, &size);
}
