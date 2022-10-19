/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_others.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:26:41 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 13:20:53 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long ptr)
{
	int		ptr_len;
	int		len;
	char	*str;

	ptr_len = 0;
	ptr_len += write(1, "0x", 2);
	if (ptr == 0)
	{
		ptr_len += write(1, "0", 1);
		return (ptr_len);
	}
	len = ft_get_hex_ptr_len(ptr);
	str = ft_get_ptr(ptr, len);
	if (!str)
		return (0);
	ft_print_str(str);
	ptr_len += len;
	free (str);
	return (ptr_len);
}

int	ft_get_hex_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

char	*ft_get_hex(unsigned int num, const char format, unsigned int len)
{
	int		i;
	char	*str;

	i = len;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	while (num != 0)
	{
		if (num % 16 <= 9)
			str[i--] = (num % 16) + '0';
		else
		{
			if (format == 'x')
				str[i--] = ((num % 16) - 10) + 'a';
			else if (format == 'X')
				str[i--] = ((num % 16) - 10) + 'A';
		}
		num = num / 16;
	}
	return (str);
}

char	*ft_get_ptr(unsigned long num, unsigned int len)
{
	int		i;
	char	*str;

	i = len;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	while (num != 0)
	{
		if (num % 16 <= 9)
			str[i--] = (num % 16) + '0';
		else
			str[i--] = ((num % 16) - 10) + 'a';
		num = num / 16;
	}
	return (str);
}
