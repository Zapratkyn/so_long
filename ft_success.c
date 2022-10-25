/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:33:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:15 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_success(t_map *map)
{
	ft_free_wall(map);
	free(map->bg->wall);
	if (map->bg->space->next)
		ft_free_space(map);
	free(map->bg->space);
	if (map->game->col->next)
		ft_free_col(map);
	free(map->game->col);
	free(map->game);
	free(map->bg);
	ft_free_images(map);
	free(map->win_ptr);
	free(map->mlx_ptr);
	free(map);
	exit(EXIT_SUCCESS);
}
