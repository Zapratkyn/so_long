/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:19:18 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 11:23:20 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_square(t_map *map, int x, int y, int color)
{
	int	a;
	int	b;
	int	i;
	int	j;

	a = (x * SIZE);
	b = (y * SIZE);
	i = a;
	j = b;
	while (i < (a + SIZE) || j < (b + SIZE))
	{
		i = a;
		while (i <= (a + SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, j, color);
			i++;
		}
		j++;
	}
}

void	ft_finder(t_map *map, int x, int y)
{
	t_col	*col;
	t_space	*space;

	col = map->game->col;
	space = map->bg->space;
	while (col)
	{
		if (x == col->x && y == col->y)
			ft_fill_square(map, x, y, 0x00FF66);
		col = col->next;
	}
	while (space)
	{
		if (x == space->x && y == space->y)
			ft_fill_square(map, x, y, 0xDADA23);
		space = space->next;
	}
}

void	ft_find(t_map *map, int x, int y)
{
	t_wall	*wall;

	wall = map->bg->wall;
	if (x == map->game->hero->x && y == map->game->hero->y)
		ft_fill_square(map, x, y, 0xFF0000);
	else if (x == map->bg->exit->x && y == map->bg->exit->y)
		ft_fill_square(map, x, y, 0x0900FF);
	else
	{
		while (wall)
		{
			if (x == wall->x && y == wall->y)
				ft_fill_square(map, x, y, 0x6C6363);
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
	while (x < map->x || y < map->y)
	{
		x = 0;
		while (x <= map->x)
		{
			ft_find(map, x, y);
			x++;
		}
		y++;
	}
}
