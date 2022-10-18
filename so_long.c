/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 17:46:21 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX/mlx.h"

int	deal_key(int key, void *param)
{
	(void)param;
	ft_putnbr_fd(key, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	(void)argc;
	(void)argv;
	x = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "So long");
	while (x <= 500)
	{
		y = 0;
		while (y <= 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x002BFF);
			y++;
		}
		x++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}