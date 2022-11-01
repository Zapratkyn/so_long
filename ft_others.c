/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:47:45 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 12:08:38 by gponcele         ###   ########.fr       */
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

void	ft_lost(t_map *map, unsigned int key_press)
{
	int		a;
	int		b;
	char	*str;

	a = (SIZE * (map->x - 1)) / 2;
	b = (SIZE * map->y) / 2;
	ft_black(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, a, b, 0xFFFFFF, "YOU LOST...");
	mlx_string_put(map->mlx_ptr, map->win_ptr, a - 20,
		b + 20, 0xFFFFFF, "PRESS Q TO QUIT");
	ft_fill_square(map, 4, map->y, 0x000000);
	ft_fill_square(map, 5, map->y, 0x000000);
	str = ft_itoa(++key_press);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		(SIZE * 4) + 5, ((map->y * SIZE) + 2), 0xFFFFFF, str);
	mlx_key_hook(map->win_ptr, deal_key_end, map);
	mlx_loop(map->mlx_ptr);
}

int	ft_close_click(int keycode, t_game *game)
{
	(void) keycode;
	(void) game;
	exit (0);
	return (0);
}

// void	ft_path_check(t_map *map, int x, int y)
// {
// 	int		a;
// 	int		b;
// 	int		c;
// 	t_wall	*wall;
// }

// void	ft_check_paths(t_map *map)
// {
// 	t_col	*col;

// 	col = map->game->col;
// 	while (col)
// 	{
// 		ft_path_check(map, col->x, col->y);
// 		col = col->next;
// 	}
// 	ft_path_check(map, map->bg->exit->x, map->bg->exit->y);
// }
