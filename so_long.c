/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/21 17:05:58 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc (sizeof(t_map));
	if (!map)
		return (0);
	map->x = 0;
	map->y = 0;
	map->win_ptr = NULL;
	map->mlx_ptr = NULL;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->g = 0;
	map->col = NULL;
	map->perso = NULL;
	map->exit = NULL;
	map->space = NULL;
	map->wall = NULL;
	return (map);
}

t_map	*ft_map(char *str)
{
	int		fd;
	t_map	*map;

	fd = open(str, O_RDONLY);
	map = map_init();
	if (!map)
		return (0);
	get_infos(map, fd);
	close(fd);
	if (map->x == map->y)
		error3("Error", map, 1);
	return (map);
}

int	deal_key(int key, t_map *param)
{
	static unsigned int	key_press = 0;

	// ft_putnbr_fd(key, 1);
	// write (1, "\n", 1);
	if (ft_move(key, param))
	{
		key_press++;
		ft_printf("Moves : %d\n", key_press);
	}
	return (0);
}

void	ft_display_walls(t_map *map)
{
	int		x;
	int		y;
	t_wall	*wall;

	x = 0;
	y = 0;
	wall = map->wall;
	while (x <= (map->x * SIZE) || y <= (map->y * SIZE))
	{
		x = 0;
		while (x <= (map->x * SIZE))
		{
			if (x == (wall->x * SIZE) && y == (wall->y * SIZE))
				ft_printf("%d - %d", x, y);	
			x += SIZE;
		}
		y += SIZE;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		error("Error\nEXPECTED FORMAT : ./so_long [map_path]");
	map = ft_map(argv[1]);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			((map->x * 65) * SIZE), ((map->y * 65) * SIZE), "So long");
	if (!map || !map->mlx_ptr || !map->win_ptr)
		exit(EXIT_FAILURE);
	// ft_display_walls(map);
	ft_draw(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}
