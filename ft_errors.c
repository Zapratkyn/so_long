/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/20 17:14:27 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error2(char *msg, t_map *map, char *str, int i)
{
	ft_putendl_fd(msg, 2);
	if (i == 1)
		ft_putendl_fd("Wrong map shape.", 2);
	else if (i == 2)
		ft_putendl_fd("Map is not surrounded by walls.", 2);
	else if (i == 3)
		ft_putendl_fd("Unwanted elements found in the map.", 2);
	if (map->col != NULL)
	{
		if (map->col->next != NULL)
			ft_free(map);
		free(map->col);
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
			ft_free(map);
		free(map->col);
	}
	free(map);
	exit(EXIT_FAILURE);
}
