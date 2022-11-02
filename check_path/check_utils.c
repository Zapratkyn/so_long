/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:54:32 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 16:54:43 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_way(t_map *map, char *line, char *next, int i)
{
	int	j;

	j = i;
	while ((i > 0) && ft_open(map, line, i))
	{
		if (ft_open(map, next, i))
			return (1);
		i--;
	}
	i = j;
	while (line[i + 1] && ft_open(map, line, i))
	{
		if (ft_open(map, next, i))
			return (1);
		i++;
	}
	return (0);
}

int	is_element_start(t_map *map, char *line, char *next, int i)
{
	if (line[i] == '0' && ft_way(map, line, next, i))
		return (1);
	if (line[i] == 'C' && ft_way(map, line, next, i))
	{
		map->c_copy--;
		return (1);
	}
	if (line[i] == 'P' && ft_way(map, line, next, i))
	{
		map->p--;
		return (1);
	}
	if (line[i] == 'E' && ft_way(map, line, next, i))
	{
		map->e--;
		return (0);
	}
	return (0);
}

int	ft_all(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] == '1' || line[i] == 'T')
		i++;
	while (line[i] && line[i - 1] != 'E' && line[i] != '1' && line[i] != 'T')
	{
		if (line[i] == 'P')
			map->p--;
		if (line[i] == 'C')
			map->c_copy--;
		if (line[i] == 'E')
			map->e--;
		i++;
	}
	if (map->e == 0 && map->c_copy == 0 && map->p == 0)
		return (1);
	return (0);
}

int	all_in_one_h(t_map *map)
{
	char	*line;
	int		y;

	y = 1;
	reset_data(map);
	line = next_line(map->map, 1, map->x);
	while (!ft_all(map, line) && y < map->y)
	{
		reset_data(map);
		free(line);
		line = next_line(map->map, 0, map->x);
		y++;
	}
	if (map->e == 0 && map->c_copy == 0 && map->p == 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	all_in_one_v(t_map *map)
{
	char	*line;
	int		x;

	x = 1;
	reset_data(map);
	line = next_col(map, 1);
	while (!ft_all(map, line) && x < map->x)
	{
		reset_data(map);
		free(line);
		line = next_col(map, 0);
		x++;
	}
	if (map->e == 0 && map->c == 0 && map->p == 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}
