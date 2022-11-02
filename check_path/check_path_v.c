/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 16:42:54 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*next_col(t_map *map, int a)
{
	int			i;
	int			j;
	static int	x = 0;
	char		str[10000];

	if (a == 1)
		x = 1;
	i = x;
	j = 0;
	while (j < map->y)
	{
		str[j++] = map->map[i];
		i += map->x;
		x++;
	}
	str[j] = '\0';
	return (ft_strdup(str));
}

int	ft_path_check_v(t_map *map, int y)
{
	char	*line;
	char	*next;
	int		*pos;

	reset_data(map);
	line = next_col(map, 0);
	while (is_wall(line))
	{
		free(line);
		line = next_col(map, 0);
		y++;
	}
	next = next_col(map, 0);
	pos = ft_pos(map, line, next);
	while (y < map->y && (!is_wall(line) || check_data(map)))
	{
		free(line);
		line = next;
		pos = is_path(map, pos, next);
		pos = is_path2(map, pos, line);
		next = next_col(map, 0);
		y++;
	}
	ft_free_path(line, next, pos);
	return (check_data_final(map));
}
