/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:47:45 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 17:35:51 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_trap(t_map *map, int x, int y, char *str)
{
	t_trap	*temp;
	t_trap	*index;

	temp = malloc (sizeof(t_trap));
	if (!temp)
		error2("Error", map, str);
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (!map->bg->trap)
		map->bg->trap = temp;
	else
	{
		index = map->bg->trap;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}

int	ft_close_click(int keycode, t_game *game)
{
	(void) keycode;
	(void) game;
	exit (0);
	return (0);
}

char	*next_line(char *map)
{
	static int	i = 0;
	int			j;
	char		str[10000];

	j = 0;
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

int	is_open(t_map *map, int i, int l)
{
	t_space	*space;
	t_col	*col;

	space = map->bg->space;
	col = map->game->col;
	while (space)
	{
		if (space->x == i && space->y == l)
			return (1);
		space = space->next;
	}
	while (col)
	{
		if (col->x == i && col->y == l)
			return (2);
		col = col->next;
	}
	return (0);
}

int	*ft_pos(t_map *map, char *line, int l)
{
	int		i;
	int		j;
	int		pos[1000];

	i = 1;
	j = 0;
	ft_bzero_int(pos, 1000);
	while (line[i + 1])
	{
		if (is_open(map, i, l) != 0)
			pos[j++] = i;
		if (is_open(map, i, l) == 2)
			map->c_copy--;
		if (map->game->hero->x == i && map->game->hero->y == l)
			map->p--;
		if (map->bg->exit->x == i && map->bg->exit->y == l)
			map->e--;
		i++;
	}
	return (ft_strdup_int(pos));
}

int	ft_is_closed(t_map *map, char *line, int l)
{
	int		i;
	t_wall	*wall;

	i = 1;
	while (line[i + 1])
	{
		wall = map->bg->wall;
		while (wall)
		{
			if (wall->x == i && wall->y == l)
				return (1);
			wall = wall->next;
		}
		i++;
	}
	i = 0;
	while (line[i + 1])
	{
		if (map->bg->exit->x == i && map->bg->exit->y == l)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_path(t_map *map, int *pos, int l)
{
	int	i;

	i = 0;
	while (pos[i])
	{
		if (is_open(map, pos[i], l + 1))
			return (1);
		i++;
	}
	return (0);
}

int	ft_path_check(t_map *map, int l)
{
	char	*line;
	int		*pos;

	line = next_line(map->map);
	while (ft_is_closed(map, line, l))
	{
		free(line);
		line = next_line(map->map);
		l++;
	}
	while (l < map->y)
	{
		ft_printf("%s\n", line);
		pos = ft_pos(map, line, l);
		if (!pos && ((map->c_copy != map->c) || (map->e != 1) || (map->p != 1)))
			break;
		if (!ft_check_path(map, pos, l))
			return (0);
		free(pos);
		free(line);
		line = next_line(map->map);
		l++;
	}
	if (map->c_copy != 0 || map->p != 0 || map->e != 0)
		return (0);
	return (1);
}
