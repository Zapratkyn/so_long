/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:22:39 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 13:16:03 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_dim(int fd, int a)
{
	int		y;
	char	*str;

	y = 0;
	str = get_next_line(fd);
	if (a == 1)
		return (ft_strlen(str) * 100);
	y++;
	free(str);
	while (str)
	{
		y++;
		str = get_next_line(fd);
		free(str);
	}
	return (y * 100);
}
