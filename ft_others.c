/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:47:45 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 15:50:20 by gponcele         ###   ########.fr       */
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

int	*is_path(t_map *map, int *pos, char *next)
{
	int	i;
	int	k;
	int	result[1000];

	i = 0;
	k = 0;
	ft_bzero_int(result, 1000);
	while (next[i])
	{
		if (is_pos(pos, i))
		{
			if (ft_open(map, next, i))
				result[k++] = i;
		}
		i++;
	}
	free(pos);
	return (ft_strdup_int(result));
}

int	*is_path2(t_map *map, int *pos, char *line)
{
	int	i;
	int	j;
	int	k;
	int	result[1000];

	i = 0;
	k = 0;
	ft_bzero_int(result, 1000);
	while (line[i])
	{
		if (is_pos(pos, i))
		{
			is_element(map, line, i);
			j = i;
			while (is_element(map, line, i - 1))
				result[k++] = i-- - 1;
			i = j;
			while (is_element(map, line, i + 1))
				result[k++] = i++ + 1;
			result[k++] = i;
		}
		i++;
	}
	free(pos);
	return (ft_strdup_int(result));
}
