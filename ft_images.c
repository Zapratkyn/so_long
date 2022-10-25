/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:45:27 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 14:32:03 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_open_image(char *file)
{
	char	*str;
	char	*result;
	int		fd;

	result = NULL;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	result = ft_strjoin(result, str);
	if (!result)
		return (0);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			result = ft_strjoin(result, str);
			if (!result)
				return (0);
		}
		free(str);
	}
	close(fd);
	return (result);
}
