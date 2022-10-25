/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:55:58 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 11:12:42 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectibles(t_map *map, int x, int y, char *str)
{
	t_col		*temp;
	t_col		*index;

	map->c += 1;
	temp = malloc (sizeof(t_col));
	if (!temp)
		error2("Error", map, str);
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (map->c == 1)
		map->game->col = temp;
	else
	{
		index = map->game->col;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}

void	ft_hero(t_map *map, int x, int y, char *str)
{
	map->p += 1;
	map->game->hero = malloc (sizeof(t_hero));
	if (!map->game->hero)
		error2("Error", map, str);
	map->game->hero->x = x;
	map->game->hero->y = y;
	map->game->hero->dir = 3;
}

void	ft_exit(t_map *map, int x, int y, char *str)
{
	map->e += 1;
	map->bg->exit = malloc (sizeof(t_exit));
	if (!map->bg->exit)
		error2("Error", map, str);
	map->bg->exit->x = x;
	map->bg->exit->y = y;
	map->bg->exit->state = 1;
}

void	ft_wall(t_map *map, int x, int y, char *str)
{
	t_wall	*temp;
	t_wall	*index;

	temp = malloc (sizeof(t_wall));
	if (!temp)
		error2("Error", map, str);
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (!map->bg->wall)
		map->bg->wall = temp;
	else
	{
		index = map->bg->wall;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}

void	ft_space(t_map *map, int x, int y, char *str)
{
	t_space	*temp;
	t_space	*index;

	temp = malloc (sizeof(t_space));
	if (!temp)
		error2("Error", map, str);
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (!map->bg->space)
		map->bg->space = temp;
	else
	{
		index = map->bg->space;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}
