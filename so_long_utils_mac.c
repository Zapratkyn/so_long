/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_mac.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 12:47:51 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, t_map *map)
{
	if (key == 13 || key == 126)
		return (ft_move_up(map));
	else if (key == 0 || key == 123)
		return (ft_move_left(map));
	else if (key == 1 || key == 125)
		return (ft_move_down(map));
	else if (key == 2 || key == 124)
		return (ft_move_right(map));
	else if (key == 5)
	{
		if (map->g == 0)
			ft_grid(map);
		else
		{
			ft_draw(map);
			map->g = 0;
		}
	}
	else if (key == 53)
	{
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
	if (key == 12)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		ft_success(map);
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
	mlx_string_put(map->mlx_ptr, map->win_ptr, a - 20, b + 20, 0xFFFFFF, "PRESS Q TO QUIT");
	mlx_key_hook(map->win_ptr, deal_key_end, map);
	mlx_loop(map->mlx_ptr);
}

t_images	*images_init(void)
{
	t_images	*images;

	images = malloc (sizeof(t_images));
	if (!images)
		return (0);
	images->hero_1 = NULL;
	images->hero_2 = NULL;
	images->hero_3 = NULL;
	images->hero_4 = NULL;
	images->exit_closed = NULL;
	images->exit_open = NULL;
	images->wall = NULL;
	images->space = NULL;
	images->col = NULL;
	return (images);
}