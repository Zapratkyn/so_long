/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 15:21:28 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error2(t_map *map, char *str, int i)
{
	if (i == 1)
		ft_putendl_fd("Error\nWrong map shape.", 2);
	else if (i == 2)
		ft_putendl_fd("Error\nMap is not surrounded by walls.", 2);
	if (map->col != NULL)
	{
		if (map->col->next != NULL)
			ft_free_col(map);
		free(map->col);
	}
	if (map->wall)
	{
		if (map->wall->next)
			ft_free_wall(map);
		free(map->wall);
	}
	if (map->space)
	{
		if (map->space->next)
			ft_free_space(map);
		free(map->space);
	}
	free(map);
	free(str);
	exit(EXIT_FAILURE);
}

void	error3(char *msg, t_map *map, int i)
{
	ft_putendl_fd(msg, 2);
	if (i == 1)
		ft_putendl_fd("Map is a square.", 2);
	else if (i == 2)
		ft_putendl_fd("Some elements are missing or several.", 2);
	if (map->col)
	{
		if (map->col->next)
			ft_free_col(map);
		free(map->col);
	}
	if (map->wall)
	{
		if (map->wall->next)
			ft_free_wall(map);
		free(map->wall);
	}
	if (map->space)
	{
		if (map->space->next)
			ft_free_space(map);
		free(map->space);
	}
	free(map);
	exit(EXIT_FAILURE);
}

void	error4(char *msg, t_map *map, char *str)
{
	ft_putendl_fd(msg, 2);
	ft_putendl_fd("Unwanted elements found in the map.", 2);
	if (map->col != NULL)
	{
		if (map->col->next != NULL)
			ft_free_col(map);
		free(map->col);
	}
	if (map->wall)
	{
		if (map->wall->next)
			ft_free_wall(map);
		free(map->wall);
	}
	if (map->space)
	{
		if (map->space->next)
			ft_free_space(map);
		free(map->space);
	}
	free(map);
	free(str);
	exit(EXIT_FAILURE);
}
