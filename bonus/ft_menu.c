/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:40:04 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/26 16:44:28 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*str;

char	*ft_theme(t_menu *menu, int i)
{
	if (i == 1)
		return ("So_long");
	else if (i == 2)
		return ("Zelda");
	else if (i == 3)
		return ("Mario");
	else if (i == 4)
	{
		mlx_destroy_window(menu->mlx_ptr, menu->win_ptr);
		free(menu);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_navigate(t_menu *menu, int i, int k)
{
	int	x;
	int	y;

	x = 150;
	y = 180;
	while (x < 200 || y < 283)
	{
		x = 150;
		while (x < 200)
		{
			mlx_pixel_put(menu->mlx_ptr, menu->win_ptr, x, y, 0x000000);
			x++;
		}
		y++;
	}
	if (i == 1)
		mlx_string_put(menu->mlx_ptr, menu->win_ptr, 150, k, 0xFFFFFF, "=>");
	else if (i == 2)
		mlx_string_put(menu->mlx_ptr, menu->win_ptr, 150, k, 0xFFFFFF, "=>");
}

void	ft_draw_menu(t_menu *menu)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	y = 0;
	size = 50;
	while (x < 500 || y < 500)
	{
		x = 0;
		while (x < 500)
		{
			mlx_pixel_put(menu->mlx_ptr, menu->win_ptr, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 150, 150, 0xFFFFFF, "PICK A THEME");
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 200, 180, 0xFFFFFF, "SO_LONG");
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 200, 210, 0xFFFFFF, "ZELDA");
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 200, 240, 0xFFFFFF, "MARIO");
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 200, 270, 0xFFFFFF, "QUIT");
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 150, 450, 0xFFFFFF, "Press SPACE to confirm");
	mlx_string_put(menu->mlx_ptr, menu->win_ptr, 150, 180, 0xFFFFFF, "=>");
}

int	deal_key_menu(int key, t_menu *menu)
{
	static int	i = 1;
	static int	y = 177;

	if ((key == 1 || key == 125) && i < 4)
	{
		y += 30;
		ft_navigate(menu, 1, y);
		i++;
	}
	else if ((key == 13 || key == 126) && i > 1)
	{
		y -= 30;
		ft_navigate(menu, 2, y);
		i--;
	}
	else if (key == 49)
	{
		str = ft_theme(menu, i);
		mlx_destroy_window(menu->mlx_ptr, menu->win_ptr);
		mlx_loop_end(menu->mlx_ptr);
	}
	return (0);
}

char	*ft_menu(void)
{
	t_menu	*menu;
	int		i;

	i = 0;
	menu = malloc (sizeof(t_menu));
	if (!menu)
		exit(EXIT_FAILURE);
	menu->mlx_ptr = NULL;
	menu->win_ptr = NULL;
	menu->mlx_ptr = mlx_init();
	menu->win_ptr = mlx_new_window(menu->mlx_ptr,
			500, 500, "So long");
	if (!menu->mlx_ptr || !menu->win_ptr)
		exit(EXIT_FAILURE);
	ft_draw_menu(menu);
	mlx_key_hook(menu->win_ptr, deal_key_menu, menu);
	mlx_loop(menu->mlx_ptr);
	free(menu);
	return (str);
}