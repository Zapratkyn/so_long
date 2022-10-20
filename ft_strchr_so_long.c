/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_so_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:30:54 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/20 16:30:21 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectibles(t_map *map, int x, int y, char *str)
{
	t_col	*temp;
	t_col	*index;

	map->c += 1;
	temp = malloc (sizeof(t_col));
	if (!temp)
		error2("Error", map, str, 0);
	temp->x = x + 1;
	temp->y = y + 1;
	temp->next = NULL;
	if (map->c == 1)
		map->col = temp;
	else
	{
		index = map->col;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
}

void	ft_strchr_element(char *str, int y, char c, t_map *map)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (c == 'P')
			{
				map->p += 1;
				map->p_x = i + 1;
				map->p_y = y + 1;
			}
			else if (c == 'E')
			{
				map->e += 1;
				map->e_x = i + 1;
				map->e_y = y + 1;
			}
			else if (c == 'C')
				ft_collectibles(map, i, y, str);
		}
		i++;
	}
}

int	ft_strchr_walls_h(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strchr_walls_v(char *str, t_map *map)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (0);
	i++;
	while ((str[i + 1]) != '\n')
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != 'C' && str[i] != 'E' && str[i] != 'P')
			error2("Error", map, str, 3);
		i++;
	}
	if (str[i] != '1')
		return (0);
	return (1);
}
