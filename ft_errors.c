/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/07 15:15:00 by gponcele         ###   ########.fr       */
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
	if (i == 3)
		ft_putendl_fd("Error\nEXPECTED FORMAT : ./so_long [map_path]", 2);
	if (i == 4)
		ft_putendl_fd("Error\nNo such map.", 2);
	exit(EXIT_FAILURE);
}

void	ft_free_rest2(t_map *map, char *msg, char *str)
{
	ft_putendl_fd(msg, 2);
	free(str);
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map->t);
	free(map->bg);
	free(map->game);
	if (map->map[1])
		free(map->map);
	free(map);
	exit(EXIT_FAILURE);
}

void	ft_free_rest3(t_map *map, char *msg)
{
	ft_putendl_fd(msg, 2);
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map->t);
	free(map->bg);
	free(map->game);
	free(map->images);
	free(map->map);
	free(map);
	exit(EXIT_FAILURE);
}

void	error2(char *msg, t_map *map, char *str)
{
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
	if (map->bg->trap)
	{
		if (map->bg->trap->next)
			ft_free_trap(map);
		free(map->bg->trap);
	}
	ft_free_rest2(map, msg, str);
}

void	error3(char *msg, t_map *map)
{
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
	if (map->bg->trap)
	{
		if (map->bg->trap->next)
			ft_free_trap(map);
		free(map->bg->trap);
	}
	ft_free_rest3(map, msg);
}
