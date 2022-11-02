/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:56 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 17:53:02 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_element(t_map *map, char *line, int i)
{
	if (line[i] == '0')
		return (1);
	if (line[i] == 'C')
	{
		map->c_copy--;
		return (1);
	}
	if (line[i] == 'P')
	{
		map->p--;
		return (1);
	}
	if (line[i] == 'E')
	{
		map->e--;
		return (0);
	}
	return (0);
}

int	*ft_pos(t_map *map, char *line, char *next)
{
	int		i;
	int		j;
	int		result[1000];

	i = 0;
	j = 0;
	ft_bzero_int(result, 1000);
	while (line[i])
	{
		if (is_element_start(map, line, next, i))
			result[j++] = i;
		i++;
	}
	return (ft_strdup_int(result));
}

int	is_pos(int *pos, int i)
{
	int	j;

	j = 0;
	while (pos[j])
	{
		if (pos[j] == i)
			return (1);
		j++;
	}
	return (0);
}

int	ft_open(t_map *map, char *next, int i)
{
	if (next[i] == '0' || next[i] == 'P' || next[i] == 'C')
		return (1);
	if (next[i] == 'E')
		map->e--;
	return (0);
}
