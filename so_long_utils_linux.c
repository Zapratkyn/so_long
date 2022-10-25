/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 15:59:36 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, t_map *map)
{
	if (key == 122 || key == 65362)
		return (ft_move_up(map));
	else if (key == 113 || key == 65361)
		return (ft_move_left(map));
	else if (key == 115 || key == 65364)
		return (ft_move_down(map));
	else if (key == 100 || key == 65363)
		return (ft_move_right(map));
	else if (key == 103)
	{
		if (map->g == 0)
			ft_grid(map);
		else
		{
			ft_draw(map);
			map->g = 0;
		}
	}
	else if (key == 65307)
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_grid(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->g = 1;
	while (x != (map->x * SIZE) || y != (map->y * SIZE))
	{
		x = 0;
		while ((y % SIZE) == 0 && x != (map->x * SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
			x++;
		}
		while ((y % SIZE) != 0 && x != (map->x * SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
			x += SIZE;
		}
		y++;
	}
}

int	deal_key_end(int key, t_map *map)
{
	if (key == 113)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_win(t_map *map)
{
	int	x;
	int	y;
	int	a;
	int	b;

	x = 0;
	y = 0;
	a = (SIZE * (map->x - 1)) / 2;
	b = (SIZE * map->y) / 2;
	while (x < (map->x * SIZE) || y < (map->y * SIZE))
	{
		x = 0;
		while (x <= (map->x * SIZE))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_string_put(map->mlx_ptr, map->win_ptr, a, b, 0xFFFFFF, "YOU WIN !!!");
	mlx_string_put(map->mlx_ptr, map->win_ptr, a - 15,
		b + 20, 0xFFFFFF, "PRESS Q TO QUIT");
	mlx_key_hook(map->win_ptr, deal_key_end, map);
	mlx_loop(map->mlx_ptr);
}
