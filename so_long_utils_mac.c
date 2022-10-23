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
	if (key == 0 || key == 123)
		return (1);
	else if (key == 1 || key == 125)
		return (1);
	else if (key == 2 || key == 124)
		return (1);
	else if (key == 13 || key == 126)
		return (1);
	else if (key == 5)
	{
		if (map->g == 1)
			ft_grid(map);
		else
			ft_draw(map);
	}
	else if (key == 53)
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
	while (x != (map->x * (65 * SIZE)) || y != (map->y * (65 * SIZE)))
	{
		x = 0;
		while (y % (65 * SIZE) == 0 && x != (map->x * (65 * SIZE)))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
			x++;
		}
		while (y % (65 * SIZE) != 0 && x != (map->x * (65 * SIZE)))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
			x += (65 * SIZE);
		}
		y++;
	}
}