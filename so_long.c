/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/20 17:10:29 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

t_map	*ft_map_init(char *str)
{
	int		fd;
	t_map	*map;

	fd = open(str, O_RDONLY);
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->p = 0;
	map->col = NULL;
	get_infos(map, fd);
	close(fd);
	if (map->x == map->y)
		error3("Error", map, 1);
	ft_printf("x = %d\ny = %d\n", map->x, map->y);
	return (map);
}

int	deal_key(int key, t_map *param)
{
	static unsigned int	key_press = 0;

	if (ft_move(key, param))
	{
		key_press++;
		ft_printf("Moves : %d\n", key_press);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		error("Error\nEXPECTED FORMAT : ./so_long [map_path]");
	map = ft_map_init(argv[1]);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			(map->x * SIZE), (map->y * SIZE), "So long");
	if (!map || !map->mlx_ptr || !map->win_ptr)
		exit(EXIT_FAILURE);
	// ft_draw(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}
