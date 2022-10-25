/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 12:49:35 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_map *map, int x, int y, t_col *col)
{
	t_col	*temp_col;
	t_space	*space;

	space = malloc (sizeof(t_space));
	if (!space)
		error3("Error", map);
	space->x = col->x;
	space->y = col->y;
	space->next = map->bg->space;
	map->bg->space = space;
	if (map->game->col->x == x && map->game->col->y == y)
		map->game->col = map->game->col->next;
	else
	{
		temp_col = map->game->col;
		while (temp_col->next)
		{
			if (temp_col->next->x == x && temp_col->next->y == y)
				temp_col->next = temp_col->next->next;
			else if (temp_col->next)
				temp_col = temp_col->next;
		}
	}
	free(col);
}

int	ft_move_up(t_map *map)
{
	t_wall	*wall;
	t_col	*col;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	while (wall)
	{
		if (x == wall->x && y == (wall->y + 1))
			return (0);
		wall = wall->next;
	}
	while (col)
	{
		if (x == col->x && y == (col->y + 1))
		{
			map->c -= 1;
			ft_collect(map, x, y - 1, col);
		}
		col = col->next;
	}
	if (x == map->bg->exit->x && y == (map->bg->exit->y + 1))
	{
		if (map->c == 0)
			ft_win(map);
		else
			return (0);
	}
	ft_fill_square(map, x, y, 0xDADA23);
	ft_fill_square(map, x, y - 1, 0xFF0000);
	map->game->hero->y -= 1;
	return (1);
}

int	ft_move_left(t_map *map)
{
	t_wall	*wall;
	t_col	*col;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	while (wall)
	{
		if (x == (wall->x + 1) && y == wall->y)
			return (0);
		wall = wall->next;
	}
	while (col)
	{
		if (x == (col->x + 1) && y == col->y)
		{
			map->c -= 1;
			ft_collect(map, x - 1, y, col);
		}
		col = col->next;
	}
	if (x == (map->bg->exit->x + 1) && y == map->bg->exit->y)
	{
		if (map->c == 0)
			ft_win(map);
		else
			return (0);
	}
	ft_fill_square(map, x, y, 0xDADA23);
	ft_fill_square(map, x - 1, y, 0xFF0000);
	map->game->hero->x -= 1;
	return (1);
}

int	ft_move_down(t_map *map)
{
	t_wall	*wall;
	t_col	*col;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	while (wall)
	{
		if (x == wall->x && y == (wall->y - 1))
			return (0);
		wall = wall->next;
	}
	while (col)
	{
		if (x == col->x && y == (col->y - 1))
		{
			map->c -= 1;
			ft_collect(map, x, y + 1, col);
		}
		col = col->next;
	}
	if (x == map->bg->exit->x && y == (map->bg->exit->y - 1))
	{
		if (map->c == 0)
			ft_win(map);
		else
			return (0);
	}
	ft_fill_square(map, x, y, 0xDADA23);
	ft_fill_square(map, x, y + 1, 0xFF0000);
	map->game->hero->y += 1;
	return (1);
}

int	ft_move_right(t_map *map)
{
	t_wall	*wall;
	t_col	*col;
	int		x;
	int		y;

	x = map->game->hero->x;
	y = map->game->hero->y;
	wall = map->bg->wall;
	col = map->game->col;
	while (wall)
	{
		if (x == (wall->x - 1) && y == wall->y)
			return (0);
		wall = wall->next;
	}
	while (col)
	{
		if (x == (col->x - 1) && y == col->y)
		{
			map->c -= 1;
			ft_collect(map, x + 1, y, col);
		}
		col = col->next;
	}
	if (x == (map->bg->exit->x - 1) && y == map->bg->exit->y)
	{
		if (map->c == 0)
			ft_win(map);
		else
			return (0);
	}
	ft_fill_square(map, x, y, 0xDADA23);
	ft_fill_square(map, x + 1, y, 0xFF0000);
	map->game->hero->x += 1;
	return (1);
}
