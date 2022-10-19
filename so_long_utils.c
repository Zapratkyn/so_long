/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:06 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 14:23:55 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, t_map *param)
{
	if (key == 0)
		return (1);
	else if (key == 1)
		return (1);
	else if (key == 2)
		return (1);
	else if (key == 13)
		return (1);
	else if (key == 53)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
