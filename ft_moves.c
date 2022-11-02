/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 17:32:45 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_stop(t_map *map, int x, int y, int i)
{
	t_wall	*wall;

	wall = map->bg->wall;
	while (wall)
	{
		if (i == 1 && (x == wall->x && y == (wall->y + 1)))
			return (1);
		if (i == 2 && (x == (wall->x + 1) && y == wall->y))
			return (1);
		if (i == 3 && (x == wall->x && y == (wall->y - 1)))
			return (1);
		if (i == 4 && (x == (wall->x - 1) && y == wall->y))
			return (1);
		wall = wall->next;
	}
	return (0);
}

int	ft_move_up(t_map *map, unsigned int key_press)
{
	ft_redraw_game(map, 1, map->game->hero->x, map->game->hero->y);
	if (ft_stop(map, map->game->hero->x, map->game->hero->y, 1))
		return (0);
	if (ft_collect(map, map->game->hero->x, map->game->hero->y, 1))
	{
		map->c -= 1;
		if (map->c == 0)
			ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
	}
	if (map->game->hero->x == map->bg->exit->x
		&& map->game->hero->y == (map->bg->exit->y + 1))
	{
		if (map->c == 0)
		{
			ft_printf("Moves : %d\n", ++key_press);
			exit(EXIT_SUCCESS);
		}
		else
			return (0);
	}
	ft_redraw_end(map, map->game->hero->x, map->game->hero->y, 1);
	map->game->hero->y -= 1;
	return (1);
}

int	ft_move_left(t_map *map, unsigned int key_press)
{
	ft_redraw_game(map, 4, map->game->hero->x, map->game->hero->y);
	if (ft_stop(map, map->game->hero->x, map->game->hero->y, 2))
		return (0);
	if (ft_collect(map, map->game->hero->x, map->game->hero->y, 2))
	{
		map->c -= 1;
		if (map->c == 0)
			ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
	}
	if (map->game->hero->x == (map->bg->exit->x + 1)
		&& map->game->hero->y == map->bg->exit->y)
	{
		if (map->c == 0)
		{
			ft_printf("Moves : %d\n", ++key_press);
			exit(EXIT_SUCCESS);
		}
		else
			return (0);
	}
	ft_redraw_end(map, map->game->hero->x, map->game->hero->y, 2);
	map->game->hero->x -= 1;
	return (1);
}

int	ft_move_down(t_map *map, unsigned int key_press)
{
	ft_redraw_game(map, 3, map->game->hero->x, map->game->hero->y);
	if (ft_stop(map, map->game->hero->x, map->game->hero->y, 3))
		return (0);
	if (ft_collect(map, map->game->hero->x, map->game->hero->y, 3))
	{
		map->c -= 1;
		if (map->c == 0)
			ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
	}
	if (map->game->hero->x == map->bg->exit->x
		&& map->game->hero->y == (map->bg->exit->y - 1))
	{
		if (map->c == 0)
		{
			ft_printf("Moves : %d\n", ++key_press);
			exit(EXIT_SUCCESS);
		}
		else
			return (0);
	}
	ft_redraw_end(map, map->game->hero->x, map->game->hero->y, 3);
	map->game->hero->y += 1;
	return (1);
}

int	ft_move_right(t_map *map, unsigned int key_press)
{
	ft_redraw_game(map, 2, map->game->hero->x, map->game->hero->y);
	if (ft_stop(map, map->game->hero->x, map->game->hero->y, 4))
		return (0);
	if (ft_collect(map, map->game->hero->x, map->game->hero->y, 4))
	{
		map->c -= 1;
		if (map->c == 0)
			ft_redraw_game(map, 5, map->bg->exit->x, map->bg->exit->y);
	}
	if (map->game->hero->x == (map->bg->exit->x - 1)
		&& map->game->hero->y == map->bg->exit->y)
	{
		if (map->c == 0)
		{
			ft_printf("Moves : %d\n", ++key_press);
			exit(EXIT_SUCCESS);
		}
		else
			return (0);
	}
	ft_redraw_end(map, map->game->hero->x, map->game->hero->y, 4);
	map->game->hero->x += 1;
	return (1);
}
