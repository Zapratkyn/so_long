/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:04:44 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 13:21:27 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int nb)
{
	char	*num;

	num = ft_itoa_printf(nb);
	ft_print_str(num);
	free(num);
	return (ft_strlen_int(nb));
}

int	ft_strlen_int_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		len;
	long	nb;
	char	*str;

	len = ft_strlen_int_unsigned(n);
	nb = n;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int nb)
{
	char	*num;

	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	num = ft_itoa_unsigned(nb);
	ft_print_str(num);
	free(num);
	return (ft_strlen_int_unsigned(nb));
}

int	ft_print_hex(unsigned int n, const char format)
{
	int		len;
	char	*str;

	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	len = ft_get_hex_ptr_len(n);
	str = ft_get_hex(n, format, len);
	if (!str)
		return (0);
	ft_print_str(str);
	free (str);
	return (len);
}
