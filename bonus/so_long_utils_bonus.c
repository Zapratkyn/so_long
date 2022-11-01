/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 13:30:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move(int key, t_map *map, unsigned int key_press)
{
	if (key == 13 || key == 126)
		return (ft_move_up(map, key_press));
	else if (key == 0 || key == 123)
		return (ft_move_left(map, key_press));
	else if (key == 1 || key == 125)
		return (ft_move_down(map, key_press));
	else if (key == 2 || key == 124)
		return (ft_move_right(map, key_press));
	else if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_black(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
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
}

int	deal_key_end(int key, t_map *map)
{
	if (key == 12)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_end(t_map *map, unsigned int key_press, int i)
{
	char	*str;

	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	map->win_ptr = mlx_new_window(map->mlx_ptr, 500, 500, "So_long");
	if (i == 0)
		mlx_string_put(map->mlx_ptr, map->win_ptr,
			200, 200, 0xFFFFFF, "YOU LOSE...");
	if (i == 1)
	{
		mlx_string_put(map->mlx_ptr, map->win_ptr,
			200, 200, 0xFFFFFF, "YOU WIN !!!");
		str = ft_itoa(++key_press);
		mlx_string_put(map->mlx_ptr, map->win_ptr,
			200, 240, 0xFFFFFF, "Moves :");
		mlx_string_put(map->mlx_ptr, map->win_ptr,
			275, 240, 0xFFFFFF, str);
	}
	mlx_string_put(map->mlx_ptr, map->win_ptr, 180,
		220, 0xFFFFFF, "PRESS Q TO QUIT");
	mlx_key_hook(map->win_ptr, deal_key_end, map);
	mlx_loop(map->mlx_ptr);
}

void	images_init(t_map *map)
{
	int	size;

	size = 1 * SIZE;
	map->images->hero = mlx_new_image(map->mlx_ptr, size, size);
	map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Hero_3.xpm"), &size, &size);
	map->images->exit = mlx_new_image(map->mlx_ptr, size, size);
	map->images->exit = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Exit_closed.xpm"), &size, &size);
	map->images->wall = mlx_new_image(map->mlx_ptr, size, size);
	map->images->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Wall.xpm"), &size, &size);
	map->images->space = mlx_new_image(map->mlx_ptr, size, size);
	map->images->space = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Ground.xpm"), &size, &size);
	map->images->col = mlx_new_image(map->mlx_ptr, size, size);
	map->images->col = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Col.xpm"), &size, &size);
	map->images->trap = mlx_new_image(map->mlx_ptr, size, size);
	map->images->trap = mlx_xpm_file_to_image(map->mlx_ptr,
			ft_strjoin2("./img/", map->t, "/Trap.xpm"), &size, &size);
}
