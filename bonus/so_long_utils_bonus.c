/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/26 17:47:15 by gponcele         ###   ########.fr       */
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

void	ft_win(t_map *map, unsigned int key_press)
{
	int		a;
	int		b;
	char	*str;

	a = (SIZE * (map->x - 1)) / 2;
	b = (SIZE * map->y) / 2;
	ft_black(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, a, b, 0xFFFFFF, "YOU WIN !!!");
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

void	images_init(t_map *map)
{
	int	size;

	size = 1 * SIZE;
	map->images->hero = mlx_new_image(map->mlx_ptr, size, size);
	map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr, ft_strjoin_theme("./images/", map->theme, "/Hero_3.xpm"), &size, &size);
	map->images->exit = mlx_new_image(map->mlx_ptr, size, size);
	map->images->exit = mlx_xpm_file_to_image(map->mlx_ptr, ft_strjoin_theme("./images/", map->theme, "/Exit_closed.xpm"), &size, &size);
	map->images->wall = mlx_new_image(map->mlx_ptr, size, size);
	map->images->wall = mlx_xpm_file_to_image(map->mlx_ptr, ft_strjoin_theme("./images/", map->theme, "/Wall.xpm"), &size, &size);
	map->images->space = mlx_new_image(map->mlx_ptr, size, size);
	map->images->space = mlx_xpm_file_to_image(map->mlx_ptr, ft_strjoin_theme("./images/", map->theme, "/Ground.xpm"), &size, &size);
	map->images->col = mlx_new_image(map->mlx_ptr, size, size);
	map->images->col = mlx_xpm_file_to_image(map->mlx_ptr, ft_strjoin_theme("./images/", map->theme, "/Col.xpm"), &size, &size);
}