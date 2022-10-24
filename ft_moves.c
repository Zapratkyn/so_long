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

int ft_move_up(t_map *map)
{
    t_wall  *wall;
    t_col   *col;
    int     x;
    int     y;

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
            map->c -= 1;
        col = col->next;
    }
    if (x == map->bg->exit->x && y == (map->bg->exit->y + 1))
    {
        if (map->c == 0)
        {
            mlx_clear_window(map->mlx_ptr, map->win_ptr);
		    mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		    exit(EXIT_SUCCESS);
        }
        else
            return (0);
    }
    ft_fill_square(map, x, y, 0xDADA23);
    ft_fill_square(map, x, y - 1, 0xFF0000);
    map->game->hero->y -= 1;
    return (1);
}

int ft_move_left(t_map *map)
{
    t_wall  *wall;
    t_col   *col;
    int     x;
    int     y;

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
            map->c -= 1;
        col = col->next;
    }
    if (x == (map->bg->exit->x + 1) && y == map->bg->exit->y)
    {
        if (map->c == 0)
        {
            mlx_clear_window(map->mlx_ptr, map->win_ptr);
		    mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		    exit(EXIT_SUCCESS);
        }
        else
            return (0);
    }
    ft_fill_square(map, x, y, 0xDADA23);
    ft_fill_square(map, x - 1, y, 0xFF0000);
    map->game->hero->x -= 1;
    return (1);
}

int ft_move_down(t_map *map)
{
    t_wall  *wall;
    t_col   *col;
    int     x;
    int     y;

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
            map->c -= 1;
        col = col->next;
    }
    if (x == map->bg->exit->x && y == (map->bg->exit->y - 1))
    {
        if (map->c == 0)
        {
            mlx_clear_window(map->mlx_ptr, map->win_ptr);
		    mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		    exit(EXIT_SUCCESS);
        }
        else
            return (0);
    }
    ft_fill_square(map, x, y, 0xDADA23);
    ft_fill_square(map, x, y + 1, 0xFF0000);
    map->game->hero->y += 1;
    return (1);
}

int ft_move_right(t_map *map)
{
    t_wall  *wall;
    t_col   *col;
    int     x;
    int     y;

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
            map->c -= 1;
        col = col->next;
    }
    if (x == (map->bg->exit->x - 1) && y == map->bg->exit->y)
    {
        if (map->c == 0)
        {
            mlx_clear_window(map->mlx_ptr, map->win_ptr);
		    mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		    exit(EXIT_SUCCESS);
        }
        else
            return (0);
    }
    ft_fill_square(map, x, y, 0xDADA23);
    ft_fill_square(map, x + 1, y, 0xFF0000);
    map->game->hero->x += 1;
    return (1);
}
