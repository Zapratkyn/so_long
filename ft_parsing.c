/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:55:58 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 16:31:46 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectibles(t_map *map, int x, int y, char *str)
{
	t_col		*temp;
	t_col		*index;
	static int	i = 1;

	map->c += 1;
	temp = malloc (sizeof(t_col));
	if (!temp)
	{
		ft_putendl_fd("Error", 2);
		error2(map, str, 0);
	}
	temp->x = x;
	temp->y = y;
	temp->index = i++;
	temp->next = NULL;
	if (map->c == 1)
		map->col = temp;
	else
	{
		index = map->col;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}

void	ft_perso(t_map *map, int x, int y, char *str)
{
	map->p += 1;
	map->perso = malloc (sizeof(t_perso));
	if (!map->perso)
	{
		ft_putendl_fd("Error", 2);
		error2(map, str, 0);
	}
	map->perso->x = x;
	map->perso->y = y;
	map->perso->dir = 3;
}

void	ft_exit(t_map *map, int x, int y, char *str)
{
	map->e += 1;
	map->exit = malloc (sizeof(t_exit));
	if (!map->exit)
	{
		ft_putendl_fd("Error", 2);
		error2(map, str, 0);
	}
	map->exit->x = x;
	map->exit->y = y;
	map->exit->state = 1;
}

void	ft_wall(t_map *map, int x, int y, char *str)
{
	t_wall	*temp;
	t_wall	*index;

	temp = malloc (sizeof(t_wall));
	if (!temp)
	{
		ft_putendl_fd("Error", 2);
		error2(map, str, 0);
	}
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (!map->wall)
		map->wall = temp;
	else
	{
		index = map->wall;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}

void	ft_space(t_map *map, int x, int y, char *str)
{
	t_space	*temp;
	t_space	*index;

	temp = malloc (sizeof(t_wall));
	if (!temp)
	{
		ft_putendl_fd("Error", 2);
		error2(map, str, 0);
	}
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (!map->space)
		map->space = temp;
	else
	{
		index = map->space;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}