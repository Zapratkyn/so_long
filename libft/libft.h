/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:00:09 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 17:05:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>

void								ft_putnbr_fd(int n, int fd);
void								ft_putstr_fd(char *s, int fd);
void								ft_putchar_fd(char c, int fd);
size_t								ft_strlen(const char *s);

#endif