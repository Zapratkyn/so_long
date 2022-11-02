/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:20:50 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/02 17:46:39 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_redraw_game(t_map *map, int i, int x, int y)
{
	int	size;

	size = 1 * SIZE;
	if (i >= 1 && i <= 4)
	{
		if (i == 1)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr,
					ft_strjoin2("./img/", map->t, "/Hero_1.xpm"), &size, &size);
		else if (i == 2)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr,
					ft_strjoin2("./img/", map->t, "/Hero_2.xpm"), &size, &size);
		else if (i == 3)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr,
					ft_strjoin2("./img/", map->t, "/Hero_3.xpm"), &size, &size);
		else if (i == 4)
			map->images->hero = mlx_xpm_file_to_image(map->mlx_ptr,
					ft_strjoin2("./img/", map->t, "/Hero_4.xpm"), &size, &size);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->images->space, x * SIZE, y * SIZE);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->images->hero, x * SIZE, y * SIZE);
	}
	else if (i == 5)
		ft_redraw_exit(map, x, y);
}

void	ft_redraw_end2(t_map *map, int x, int y, int i)
{
	void	*space;
	void	*hero;
	void	*mp;
	void	*wp;

	space = map->images->space;
	hero = map->images->hero;
	mp = map->mlx_ptr;
	wp = map->win_ptr;
	if (i == 3)
	{
		mlx_put_image_to_window(mp, wp, space, x * SIZE, y * SIZE);
		mlx_put_image_to_window(mp, wp, space, x * SIZE, (y + 1) * SIZE);
		mlx_put_image_to_window(mp, wp, hero, x * SIZE, (y + 1) * SIZE);
	}
	if (i == 4)
	{
		mlx_put_image_to_window(mp, wp, space, x * SIZE, y * SIZE);
		mlx_put_image_to_window(mp, wp, space, (x + 1) * SIZE, y * SIZE);
		mlx_put_image_to_window(mp, wp, hero, (x + 1) * SIZE, y * SIZE);
	}
}

void	ft_redraw_end(t_map *map, int x, int y, int i)
{
	void	*space;
	void	*hero;
	void	*mp;
	void	*wp;

	space = map->images->space;
	hero = map->images->hero;
	mp = map->mlx_ptr;
	wp = map->win_ptr;
	if (i == 1)
	{
		mlx_put_image_to_window(mp, wp, space, x * SIZE, y * SIZE);
		mlx_put_image_to_window(mp, wp, space, x * SIZE, (y - 1) * SIZE);
		mlx_put_image_to_window(mp, wp, hero, x * SIZE, (y - 1) * SIZE);
	}
	if (i == 2)
	{
		mlx_put_image_to_window(mp, wp, space, x * SIZE, y * SIZE);
		mlx_put_image_to_window(mp, wp, space, (x - 1) * SIZE, y * SIZE);
		mlx_put_image_to_window(mp, wp, hero, (x - 1) * SIZE, y * SIZE);
	}
	if (i > 2)
		ft_redraw_end2(map, x, y, i);
}

int	ft_collect2(t_map *map, int x, int y, int i)
{
	t_col	*col;

	col = map->game->col;
	while (col)
	{
		if (i == 3 && (x == col->x && y == (col->y - 1)) && col->state == 1)
		{
			col->state = 0;
			return (1);
		}
		if (i == 4 && (x == (col->x - 1) && y == col->y) && col->state == 1)
		{
			col->state = 0;
			return (1);
		}
		col = col->next;
	}
	return (0);
}

int	ft_collect(t_map *map, int x, int y, int i)
{
	t_col	*col;

	col = map->game->col;
	while (col)
	{
		if (i == 1 && (x == col->x && y == (col->y + 1)) && col->state == 1)
		{
			col->state = 0;
			return (1);
		}
		if (i == 2 && (x == (col->x + 1) && y == col->y) && col->state == 1)
		{
			col->state = 0;
			return (1);
		}
		col = col->next;
	}
	if (i > 2)
		return (ft_collect2(map, x, y, i));
	return (0);
}
