/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 14:33:57 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

t_map	*ft_map_init(char *str)
{
	int		fd;
	t_map	*temp;

	fd = open(str, O_RDONLY);
	temp = malloc(sizeof(t_map));
	if (!temp)
		return (0);
	temp->x = get_dim(fd, 1);
	temp->y = get_dim(fd, 0);
	close(fd);
	return (temp);
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

	(void)argc;
	map = ft_map_init(argv[1]);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->x, map->y, "So long");
	if (!map || !map->mlx_ptr || !map->win_ptr)
		exit(EXIT_FAILURE);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}
