/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:41 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 13:02:45 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_trap(t_map *map)
{
	t_trap	*temp;
	t_trap	*index;

	while (map->bg->trap->next->next)
	{
		index = map->bg->trap->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->bg->trap->next);
}

void	ft_free_col(t_map *map)
{
	t_col	*temp;
	t_col	*index;

	while (map->game->col->next->next)
	{
		index = map->game->col->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->game->col->next);
}

void	ft_free_wall(t_map *map)
{
	t_wall	*temp;
	t_wall	*index;

	while (map->bg->wall->next->next)
	{
		index = map->bg->wall->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->bg->wall->next);
}

void	ft_free_space(t_map *map)
{
	t_space	*temp;
	t_space	*index;

	while (map->bg->space->next->next)
	{
		index = map->bg->space->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->bg->space->next);
}

int	ft_free_images(t_map *map)
{
	if (map->images)
	{
		if (map->images->hero)
			free(map->images->hero);
		if (map->images->exit)
			free(map->images->exit);
		if (map->images->wall)
			free(map->images->wall);
		if (map->images->space)
			free(map->images->space);
		if (map->images->col)
			free(map->images->col);
		if (map->images->trap)
			free(map->images->trap);
		free(map->images);
	}
	return (0);
}
