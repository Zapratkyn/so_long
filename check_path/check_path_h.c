/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 16:09:07 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*next_line(char *map, int a, int x)
{
	static int	i = 0;
	int			j;
	char		str[10000];

	j = 0;
	if (a == 1)
		i = x + 1;
	while (map[i] != '\n')
	{
		str[j] = map[i];
		j++;
		i++;
	}
	i++;
	str[j] = '\0';
	return (ft_strdup(str));
}

int	ft_path_check_h(t_map *map, int y)
{
	char	*line;
	char	*next;
	int		*pos;

	reset_data(map);
	line = next_line(map->map, 0, map->x);
	while (is_wall(line))
	{
		free(line);
		line = next_line(map->map, 0, map->x);
		y++;
	}
	next = next_line(map->map, 0, map->x);
	pos = ft_pos(map, line, next);
	while (y < map->y && (!is_wall(line) || check_data(map)))
	{
		free(line);
		line = next;
		pos = is_path(map, pos, next);
		pos = is_path2(map, pos, line);
		next = next_line(map->map, 0, map->x);
		y++;
	}
	ft_free_path(line, next, pos);
	return (check_data_final(map));
}
