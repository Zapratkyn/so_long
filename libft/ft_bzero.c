/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:35:38 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 16:38:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(char *str, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_bzero_int(int *str, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		str[i] = '\0';
		i++;
	}
}