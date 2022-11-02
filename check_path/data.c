/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 15:27:45 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reset_data(t_map *map)
{
	map->e = 1;
	map->p = 1;
	map->c_copy = map->c;
}

int	check_data(t_map *map)
{
	if (map->e == 1 && map->c_copy == map->c && map->p == 1)
		return (1);
	return (0);
}

int	check_data_final(t_map *map)
{
	if (map->e == 1 || map->p == 1 || map->c_copy != 0)
		return (0);
	return (1);
}

void	ft_free_path(char *line, char *next, int *pos)
{
	free(line);
	free(next);
	free(pos);
}
