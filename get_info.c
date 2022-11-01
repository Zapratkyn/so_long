/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:22:39 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 13:32:51 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_len(t_map *map, char *str)
{
	if ((ft_strlen(str) - 1) != map->x)
		error2("Error\nWrong map shape", map, str);
}

void	get_infos(t_map *map, int fd)
{
	char		*str;
	char		*next;
	static int	y = 0;

	str = get_next_line(fd);
	map->x = (ft_strlen(str) - 1);
	map->map = str;
	if (!ft_strchr_walls_h(str))
		error2("Error\nMap is not surrounded by walls.", map, str);
	get_element(str, map, y++);
	next = get_next_line(fd);
	while (next && next[0] != '\n')
	{
		free(str);
		str = next;
		check_len(map, str);
		map->map = ft_strjoin(map->map, str);
		get_element(str, map, y++);
		next = get_next_line(fd);
	}
	free(next);
	if (!ft_strchr_walls_h(str))
		error2("Error\nMap is not surrounded by walls.", map, str);
	free(str);
	map->y = y;
}

void	get_element(char *str, t_map *map, int y)
{
	if (!ft_strchr_walls_v(str, map))
	{
		if (!ft_strchr_walls_h(str))
			error2("Error\nMap is not surrounded by walls.", map, str);
	}
	ft_strchr_element(str, y, 'C', map);
	ft_strchr_element(str, y, 'E', map);
	ft_strchr_element(str, y, 'P', map);
	ft_strchr_element(str, y, '0', map);
	ft_strchr_element(str, y, '1', map);
	ft_strchr_element(str, y, 'T', map);
}
