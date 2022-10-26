/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:20:50 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/26 14:28:36 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_redraw_game(t_map *map, int i, int x, int y)
{
	int	size;

	size = 1 * SIZE;
	if (i >= 1 && i <= 4)
	{
		if (i == 1)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr, "./images/Zelda/Hero_1.xpm", &size, &size);
		else if (i == 2)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr, "./images/Zelda/Hero_2.xpm", &size, &size);
		else if (i == 3)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr, "./images/Zelda/Hero_3.xpm", &size, &size);
		else if (i == 4)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr, "./images/Zelda/Hero_4.xpm", &size, &size);
		mlx_put_image_to_window(map->mlx_ptr,
				map->win_ptr, map->images->space, x * SIZE, y * SIZE);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->images->hero, x * SIZE, y * SIZE);
	}
	else if (i == 5)
	{
		map->images->exit = mlx_xpm_file_to_image(map->mlx_ptr, "./images/Zelda/Exit_open.xpm", &size, &size);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->images->exit, x * SIZE, y * SIZE);
	}
}