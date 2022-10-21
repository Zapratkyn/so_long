/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:41 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 15:22:46 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_col(t_map *map)
{
	t_col	*temp;
	t_col	*index;

	while (map->col->next->next)
	{
		index = map->col->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->col->next);
}

void	ft_free_wall(t_map *map)
{
	t_wall	*temp;
	t_wall	*index;

	while (map->wall->next->next)
	{
		index = map->wall->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->wall->next);
}

void	ft_free_space(t_map *map)
{
	t_space	*temp;
	t_space	*index;

	while (map->space->next->next)
	{
		index = map->space->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(map->space->next);
}
