/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:48:25 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/19 13:20:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_check_formats(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_formats(va_list ap, const char format)
{
	int	a;

	a = 0;
	if (format == 'c')
		a = ft_print_char(va_arg(ap, int));
	else if (format == 's')
		a = ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		a = ft_print_ptr(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		a = ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		a = ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		a = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		a = ft_print_percent();
	return (a);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		return_value;

	i = -1;
	return_value = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && ft_check_formats(s[i + 1], "cspdiuxX%"))
		{
			return_value += ft_formats(ap, s[i + 1]);
			i++;
		}
		else if (s[i] == '%' && !ft_check_formats(s[i + 1], "cspdiuxX%"))
		{
			return_value += ft_print_char(s[i + 1]);
			i++;
		}
		else
			return_value += ft_print_char(s[i]);
	}
	va_end(ap);
	return (return_value);
}
