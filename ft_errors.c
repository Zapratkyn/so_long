/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 16:36:01 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error2(char *msg, t_map *map, char *str)
{
	ft_putendl_fd(msg, 2);
	if (map->game->col)
	{
		if (map->game->col->next)
			ft_free_col(map);
		free(map->game->col);
	}
	if (map->bg->wall)
	{
		if (map->bg->wall->next)
			ft_free_wall(map);
		free(map->bg->wall);
	}
	if (map->bg->space)
	{
		if (map->bg->space->next)
			ft_free_space(map);
		free(map->bg->space);
	}
	free(map->game);
	free(map->bg);
	// ft_free_images(map);
	free(map);
	free(str);
	exit(EXIT_FAILURE);
}

void	error3(char *msg, t_map *map)
{
	ft_putendl_fd(msg, 2);
	if (map->game->col)
	{
		if (map->game->col->next)
			ft_free_col(map);
		free(map->game->col);
	}
	if (map->bg->wall)
	{
		if (map->bg->wall->next)
			ft_free_wall(map);
		free(map->bg->wall);
	}
	if (map->bg->space)
	{
		if (map->bg->space->next)
			ft_free_space(map);
		free(map->bg->space);
	}
	free(map->game);
	free(map->bg);
	// ft_free_images(map);
	free(map);
	exit(EXIT_FAILURE);
}
