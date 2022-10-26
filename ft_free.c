/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:41 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/26 12:09:07 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_col(t_map *map)
{
	t_col	*temp;
	t_col	*index;

	if (map->game->hero)
		free(map->game->hero);
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

	if (map->bg->exit)
		free(map->bg->exit);
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

	if (map->bg->exit)
		free(map->bg->exit);
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
		free(map->images);
	}
	return (0);
}
