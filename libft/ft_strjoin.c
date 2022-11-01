/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:58:03 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 12:45:28 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	else
	{
		i = -1;
		j = -1;
		while (s1[++i])
			str[i] = s1[i];
		while (s2[++j])
			str[i++] = s2[j];
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = malloc (sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + ft_strlen(s3) + 1));
	if (!s1 || !s2 || !s3 || !str)
		return (0);
	i = -1;
	j = -1;
	k = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	while (s3[++k])
		str[i++] = s3[k];
	str[i] = '\0';
	return (str);
}
