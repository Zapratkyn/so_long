/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/31 16:42:55 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int i)
{
	if (i == 1)
		ft_putendl_fd("Error\nEXPECTED FORMAT : ./so_long [map_path] Theme", 2);
	else if (i == 2)
	{
		ft_putendl_fd("Available themes :\n* So_long", 2);
		ft_putendl_fd("* Zelda\n* Mario\n(Spelling matters)", 2);
	}
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
	ft_free_rest(map);
	free(map->images);
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
	ft_free_rest(map);
	free(map->images);
	free(map);
	exit(EXIT_FAILURE);
}
