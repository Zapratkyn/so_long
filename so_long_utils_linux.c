/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 16:39:43 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, t_map *map)
{
	if (key == 122 || key == 65362)
		return (ft_move_up(map));
	else if (key == 113 || key == 65361)
		return (ft_move_left(map));
	else if (key == 115 || key == 65364)
		return (ft_move_down(map));
	else if (key == 100 || key == 65363)
		return (ft_move_right(map));
	else if (key == 103)
	{
		if (map->g == 0)
			ft_grid(map);
		else
		{
			ft_draw(map);
			map->g = 0;
		}
	}
	else if (key == 65307)
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_grid(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->g = 1;
	while (x != (map->x * SIZE) || y != (map->y * SIZE))
	{
		x = 0;
		while ((y % SIZE) == 0 && x != (map->x * SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
			x++;
		}
		while ((y % SIZE) != 0 && x != (map->x * SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
			x += SIZE;
		}
		y++;
	}
}