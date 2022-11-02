/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:47:37 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 17:52:05 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_lose(t_map *map, int x, int y, int i)
{
	t_trap	*trap;

	trap = map->bg->trap;
	while (trap)
	{
		if (i == 1 && (x == trap->x && y == (trap->y + 1)))
			return (1);
		if (i == 2 && (x == (trap->x + 1) && y == trap->y))
			return (1);
		if (i == 3 && (x == trap->x && y == (trap->y - 1)))
			return (1);
		if (i == 4 && (x == (trap->x - 1) && y == trap->y))
			return (1);
		trap = trap->next;
	}
	return (0);
}
