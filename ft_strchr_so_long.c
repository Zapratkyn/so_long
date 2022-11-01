/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_so_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:30:54 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/31 16:29:48 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strchr_element(char *str, int y, char c, t_map *map)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == c)
		{
			if (c == 'P')
				ft_hero(map, i, y, str);
			else if (c == 'E')
				ft_exit(map, i, y, str);
			else if (c == 'C')
				ft_collectibles(map, i, y, str);
			else if (c == '1')
				ft_wall(map, i, y, str);
			else if (c == '0')
				ft_space(map, i, y, str);
			else if (c == 'T')
				ft_trap(map, i, y, str);
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
			error2("Error\nUnwanted elements found in the map.", map, str);
		i++;
	}
	if (str[i] != '1')
		return (0);
	return (1);
}
