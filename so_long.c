/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/31 16:34:37 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc (sizeof(t_map));
	map->x = 0;
	map->y = 0;
	map->win_ptr = NULL;
	map->mlx_ptr = NULL;
	map->t = NULL;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->g = 0;
	map->d = 0;
	map->bg = malloc (sizeof(t_bg));
	map->game = malloc (sizeof(t_game));
	map->images = malloc (sizeof(t_images));
	if (!map || !map->bg || !map->game || !map->images)
		return (0);
	map->bg->wall = NULL;
	map->bg->space = NULL;
	map->bg->exit = NULL;
	map->game->hero = NULL;
	map->game->col = NULL;
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
		error3("Error\nThe map is a square.", map);
	if (map->x > 52 || map->y > 25)
		error3("Error\nThe map is too big for the screen.", map);
	// if (!ft_check_paths(map))
	// 	error3("Error\nUnreachable item or exit.", map);
	return (map);
}

int	deal_key(int key, t_map *map)
{
	static unsigned int	key_press = 0;
	char				*str;

	if (ft_move(key, map, key_press) == 1)
	{
		key_press++;
		str = ft_itoa(key_press);
		ft_printf("Moves : %d\n", key_press);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		error(1);
	map = ft_map(argv[1]);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
			(map->x * SIZE), (map->y * SIZE), "So long");
	if (!map || !map->mlx_ptr || !map->win_ptr)
		exit(EXIT_FAILURE);
	images_init(map);
	ft_draw(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}
