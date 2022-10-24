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
	map->x = 0;
	map->y = 0;
	map->win_ptr = NULL;
	map->mlx_ptr = NULL;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->g = 0;
	map->bg = malloc (sizeof(t_bg));
	map->game = malloc (sizeof(t_game));
	if (!map || !map->bg || !map->game)
		return (0);
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
		error3("Error\nSome elements are missing or several.", map);
	// if (!ft_check_paths(map))
	// 	error3("Error\nUnreachable item or exit.", map);
	return (map);
}

int	deal_key(int key, t_map *map)
{
	static unsigned int	key_press = 0;
	char				*str;

	if (ft_move(key, map))
	{
		key_press++;
		ft_fill_square(map, 1, 0, 0x000000);
		str = ft_itoa(key_press);
		mlx_string_put(map->mlx_ptr, map->win_ptr, SIZE + 5, (SIZE / 2), 0xFFFFFF, str);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		error("Error\nEXPECTED FORMAT : ./so_long [map_path]");
	map = ft_map(argv[1]);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			(map->x * SIZE), (map->y * SIZE), "So long");
	if (!map || !map->mlx_ptr || !map->win_ptr)
		exit(EXIT_FAILURE);
	ft_draw(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, (SIZE / 2), 0xFFFFFF, "Moves :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, SIZE + 5, ((SIZE / 2) + 2), 0xFFFFFF, "0");
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}
