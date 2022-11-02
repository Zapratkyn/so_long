/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:19:18 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 17:46:48 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		while (i < (a + SIZE))
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
	t_trap	*trap;

	col = map->game->col;
	trap = map->bg->trap;
	while (col)
	{
		if (x == col->x && y == col->y)
			mlx_put_image_to_window(map->mlx_ptr,
				map->win_ptr, map->images->col, x * SIZE, y * SIZE);
		col = col->next;
	}
	while (trap)
	{
		if (x == trap->x && y == trap->y)
			mlx_put_image_to_window(map->mlx_ptr,
				map->win_ptr, map->images->trap, x * SIZE, y * SIZE);
		trap = trap->next;
	}
}

void	ft_find(t_map *map, int x, int y)
{
	t_wall	*wall;
	t_col	*col;

	wall = map->bg->wall;
	col = map->game->col;
	if (x == map->game->hero->x && y == map->game->hero->y)
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->images->hero, x * SIZE, y * SIZE);
	else if (x == map->bg->exit->x && y == map->bg->exit->y)
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->images->exit, x * SIZE, y * SIZE);
	else
	{
		while (wall)
		{
			if (x == wall->x && y == wall->y)
				mlx_put_image_to_window(map->mlx_ptr,
					map->win_ptr, map->images->wall, x * SIZE, y * SIZE);
			wall = wall->next;
		}
	}
	ft_finder(map, x, y);
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
			mlx_put_image_to_window(map->mlx_ptr,
				map->win_ptr, map->images->space, x * SIZE, y * SIZE);
			ft_find(map, x, y);
			x++;
		}
		y++;
	}
}

void	ft_redraw_exit(t_map *map, int x, int y)
{
	int	size;

	size = 1 * SIZE;
	map->images->exit = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Exit_open.xpm"), &size, &size);
	mlx_put_image_to_window(map->mlx_ptr,
		map->win_ptr, map->images->space, x * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr,
		map->win_ptr, map->images->exit, x * SIZE, y * SIZE);
}
