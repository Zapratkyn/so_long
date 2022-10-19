/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 13:45:16 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
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

int	deal_key(int key, void *param)
{
	static int	key_press = 0;
	
	(void)param;
	if (ft_move(key))
	{
		key_press++;
		printf("Moves : %d\n", key_press);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;

	(void)argc;
	mlx_ptr = mlx_init();
	map = ft_map_init(argv[1]);
	if (!map || mlx_ptr)
		exit(EXIT_FAILURE);
	win_ptr = mlx_new_window(mlx_ptr, map->x, map->y, "So long");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
