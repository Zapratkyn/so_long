/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:30:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 17:07:31 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX/mlx.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_loop(mlx_ptr);
}