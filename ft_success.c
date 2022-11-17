/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:43:33 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/17 16:01:10 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_rest(t_map *map)
{
	free(map->mlx_ptr);
	free(map->bg);
	free(map->game);
	free(map);
	exit(EXIT_FAILURE);
}

void	ft_success(t_map *map)
{
	if (map->game->col->next)
		ft_free_col(map);
	free(map->game->col);
	ft_free_wall(map);
	free(map->bg->wall);
	ft_free_space(map);
	free(map->bg->space);
	if (map->bg->trap)
	{
		if (map->bg->trap->next)
			ft_free_trap(map);
		free(map->bg->trap);
	}
	ft_free_rest(map);
}