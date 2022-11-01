/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 12:25:17 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move_up(t_map *map, unsigned int key_press)
{
	t_wall	*wall;
	t_col	*col;
	t_trap	*trap;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	trap = map->bg->trap;
	ft_redraw_game(map, 1, x, y);
	while (wall)
	{
		if (x == wall->x && y == (wall->y + 1))
			return (0);
		wall = wall->next;
	}
	while (trap)
	{
		if (x == trap->x && y == (trap->y + 1))
			ft_end(map, key_press, 0);
		trap = trap->next;
	}
	while (col)
	{
		if (x == col->x && y == (col->y + 1) && col->state == 1)
		{
			map->c -= 1;
			if (map->c == 0)
				ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
			col->state = 0;
		}
		col = col->next;
	}
	if (x == map->bg->exit->x && y == (map->bg->exit->y + 1))
	{
		if (map->c == 0)
			ft_end(map, key_press, 1);
		else
			return (0);
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, x * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, x * SIZE, (y - 1) * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->hero, x * SIZE, (y - 1) * SIZE);
	map->game->hero->y -= 1;
	return (1);
}

int	ft_move_left(t_map *map, unsigned int key_press)
{
	t_wall	*wall;
	t_col	*col;
	t_trap	*trap;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	trap = map->bg->trap;
	ft_redraw_game(map, 4, x, y);
	while (wall)
	{
		if (x == (wall->x + 1) && y == wall->y)
			return (0);
		wall = wall->next;
	}
	while (trap)
	{
		if (x == (trap->x + 1) && y == trap->y)
			ft_end(map, key_press, 0);
		trap = trap->next;
	}
	while (col)
	{
		if (x == (col->x + 1) && y == col->y && col->state == 1)
		{
			map->c -= 1;
			if (map->c == 0)
				ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
			col->state = 0;
		}
		col = col->next;
	}
	if (x == (map->bg->exit->x + 1) && y == map->bg->exit->y)
	{
		if (map->c == 0)
			ft_end(map, key_press, 1);
		else
			return (0);
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, x * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, (x - 1) * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->hero, (x - 1) * SIZE, y * SIZE);
	map->game->hero->x -= 1;
	return (1);
}

int	ft_move_down(t_map *map, unsigned int key_press)
{
	t_wall	*wall;
	t_col	*col;
	t_trap	*trap;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	trap = map->bg->trap;
	ft_redraw_game(map, 3, x, y);
	while (wall)
	{
		if (x == wall->x && y == (wall->y - 1))
			return (0);
		wall = wall->next;
	}
	while (trap)
	{
		if (x == trap->x && y == (trap->y - 1))
			ft_end(map, key_press, 0);
		trap = trap->next;
	}
	while (col)
	{
		if (x == col->x && y == (col->y - 1) && col->state == 1)
		{
			map->c -= 1;
			if (map->c == 0)
				ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
			col->state = 0;
		}
		col = col->next;
	}
	if (x == map->bg->exit->x && y == (map->bg->exit->y - 1))
	{
		if (map->c == 0)
			ft_end(map, key_press, 1);
		else
			return (0);
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, x * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, x * SIZE, (y + 1) * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->hero, x * SIZE, (y + 1) * SIZE);
	map->game->hero->y += 1;
	return (1);
}

int	ft_move_right(t_map *map, unsigned int key_press)
{
	t_wall	*wall;
	t_col	*col;
	t_trap	*trap;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	trap = map->bg->trap;
	ft_redraw_game(map, 2, x, y);
	while (wall)
	{
		if (x == (wall->x - 1) && y == wall->y)
			return (0);
		wall = wall->next;
	}
	while (trap)
	{
		if (x == (trap->x - 1) && y == trap->y)
			ft_end(map, key_press, 0);
		trap = trap->next;
	}
	while (col)
	{
		if (x == (col->x - 1) && y == col->y && col->state == 1)
		{
			map->c -= 1;
			if (map->c == 0)
				ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
			col->state = 0;
		}
		col = col->next;
	}
	if (x == (map->bg->exit->x - 1) && y == map->bg->exit->y)
	{
		if (map->c == 0)
			ft_end(map, key_press, 1);
		else
			return (0);
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, x * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->space, (x + 1) * SIZE, y * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->images->hero, (x + 1) * SIZE, y * SIZE);
	map->game->hero->x += 1;
	return (1);
}
