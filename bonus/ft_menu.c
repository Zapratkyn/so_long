/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:40:04 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/31 11:52:55 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_theme(t_map *map, int i)
{
	if (i == 1)
		map->t = "So_long";
	else if (i == 2)
		map->t = "Zelda";
	else if (i == 3)
		map->t = "Mario";
	else if (i == 4)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			(map->x * SIZE), ((map->y + 1) * SIZE), "So long");
	if (!map->win_ptr)
		exit (EXIT_FAILURE);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10,
		((map->y * SIZE) + 2), 0xFFFFFF, "Moves   :");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		(SIZE * 4) + 5, ((map->y * SIZE) + 2), 0xFFFFFF, "0");
	images_init(map);
	ft_draw(map);
	map->m = 0;
}

void	ft_navigate(t_map *map, int k)
{
	int	x;
	int	y;

	x = 150;
	y = 180;
	while (x < 200 || y < 283)
	{
		x = 150;
		while (x < 200)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_string_put(map->mlx_ptr, map->win_ptr, 150, k, 0xFFFFFF, "=>");
}

void	ft_draw_menu(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		150, 150, 0xFFFFFF, "PICK A THEME");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 200, 180, 0xFFFFFF, "SO_LONG");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 200, 210, 0xFFFFFF, "ZELDA");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 200, 240, 0xFFFFFF, "MARIO");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 200, 270, 0xFFFFFF, "QUIT");
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		150, 450, 0xFFFFFF, "Press SPACE to confirm");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 150, 180, 0xFFFFFF, "=>");
}

int	deal_key_menu(int key, t_map *map)
{
	static int	i = 1;
	static int	y = 177;

	if ((key == 1 || key == 125) && i < 4)
	{
		y += 30;
		ft_navigate(map, y);
		i++;
	}
	else if ((key == 13 || key == 126) && i > 1)
	{
		y -= 30;
		ft_navigate(map, y);
		i--;
	}
	else if (key == 49)
		ft_theme(map, i);
	return (0);
}
