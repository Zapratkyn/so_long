/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:22:39 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 10:59:45 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_infos(t_map *map, int fd)
{
	char		*str;
	static int	y = 0;

	str = get_next_line(fd);
	map->x = (ft_strlen(str) - 1);
	get_element(str, map, y);
	y++;
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			if ((ft_strlen(str) - 1) != map->x)
				error2("Error\nWrong map shape", map, str);
			get_element(str, map, y);
			y++;
		}
		free(str);
	}
	map->y = y;
	if (map->c < 1 || map->e != 1 || map->p != 1)
		error3("Error\nSome elements are missing or several.", map);
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
}
