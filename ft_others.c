/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:47:45 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/10 09:24:28 by gponcele         ###   ########.fr       */
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

int	check_map(char *str)
{
	if (!ft_strcmp(str, "maps/1.ber"))
		return (1);
	if (!ft_strcmp(str, "maps/2.ber"))
		return (1);
	if (!ft_strcmp(str, "maps/3.ber"))
		return (1);
	if (!ft_strcmp(str, "maps/4.ber"))
		return (1);
	return (0);
}

int	ft_check_path(t_map *map)
{
	int	i;

	i = (((map->x * map->game->hero->y) + map->game->hero->x) + 1);
	ft_grid(map, i);
	free(map-map);
	if (map->c_copy != 0 || map->e == 1)
		return (0);
	return (1);
}

void	ft_grid(t_map *map, int i)
{
	if (map->map[i] == 'C')
		map->c_copy--;
	if (map->map[i] == 'E')
		map->e--;
	if (i < 0 || !map->map[i] || map->map[i] == '1'
		|| map->map[i] == 'X' || map->map[i] == 'E' || map->map[i] == 'T')
		return ;
	map->map[i] = 'X';
	ft_grid(map, (i + (map->x + 1)));
	ft_grid(map, (i - (map->x + 1)));
	ft_grid(map, i + 1);
	ft_grid(map, i - 1);
	return ;
}
