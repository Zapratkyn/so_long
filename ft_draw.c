/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:19:18 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 16:39:57 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_square(t_map *map, int x, int y, int color)
{
	int	a;
	int	b;

	a = x;
	b = y;
	while (a <= (x + SIZE) || b <= (y + SIZE))
	{
		a = 0;
		while (a <= (x + SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, a, b, color);
			a++;
		}
		b++;
	}
}

void	ft_finder(t_map *map, int x, int y)
{
	t_col	*col;
	t_space	*space;

	col = map->col;
	space = map->space;
	while (col)
	{
		if (x == (col->x * SIZE) && y == (col->y * SIZE))
			ft_fill_square(map, x, y, 0x00FF66);
		col = col->next;
	}
	while (space)
	{
		if (x == (space->x * SIZE) && y == (space->y * SIZE))
			ft_fill_square(map, x, y, 0xDADA23);
		space = space->next;
	}
}

void	ft_find(t_map *map, int x, int y)
{
	t_wall	*wall;

	wall = map->wall;
	if (x == (map->perso->x * SIZE) && y == (map->perso->y * SIZE))
		ft_fill_square(map, x, y, 0xFF0000);
	else if (x == (map->exit->x * SIZE) && (y == map->perso->y * SIZE))
		ft_fill_square(map, x, y, 0x0900FF);
	else
	{
		while (wall)
		{
			if (x == (wall->x * SIZE) && y == (wall->y * SIZE))
				ft_fill_square(map, x, y, 0x000000);
			wall = wall->next;
		}
		ft_finder(map, x, y);
	}
}

void	ft_draw(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->g = 1;
	while (x <= (map->x * SIZE) || y <= (map->y * SIZE))
	{
		x = 0;
		while (x <= (map->x * SIZE))
		{
			ft_find(map, x, y);
			x += SIZE;
		}
		y += SIZE;
	}
}
