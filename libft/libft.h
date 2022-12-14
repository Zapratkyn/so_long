/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:00:09 by gponcele          #+#    #+#             */
/*   Updated: 2022/11/01 16:38:34 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>
# include	<stdarg.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

void								ft_putnbr_fd(int n, int fd);
void								ft_putstr_fd(char *s, int fd);
void								ft_putchar_fd(char c, int fd);
int									ft_strlen(const char *s);
char								*empty_string(void);
char								*ft_strjoin(char *s1, char *s2);
char								*ft_strjoin_gnl(char *s1, char *s2);
char								*ft_strchr(char *s, int c);
char								*get_next_line(int fd);
void								ft_bzero(char *str, int k);
void								ft_bzero_int(int *str, int k);
void								ft_putendl_fd(char *s, int fd);
int									ft_printf(const char *s, ...);
int									ft_formats(va_list ap, const char format);
int									ft_check_formats(char c, char *set);
int									ft_print_str(char *str);
char								*ft_strdup(char *str);
int									*ft_strdup_int(int *str);
int									ft_print_percent(void);
int									ft_print_char(char c);
int									ft_strlen_int(int n);
int									ft_strlen_i(int *str);
int									ft_strcmp(const char *s1, const char *s2);
char								*ft_itoa_printf(int n);
char								*ft_strjoin2(char *s1,
										char *s2, char *s3);
int									ft_print_nbr(int nb);
char								*ft_itoa(int n);
int									ft_strlen_int_unsigned(unsigned int n);
char								*ft_itoa_unsigned(unsigned int n);
int									ft_print_unsigned(unsigned int nb);
int									ft_print_hex(unsigned int n,
										const char format);
int									ft_print_ptr(unsigned long ptr);
int									ft_get_hex_ptr_len(unsigned long n);
char								*ft_get_hex(unsigned int num,
										const char format, unsigned int len);
char								*ft_get_ptr(unsigned long num,
										unsigned int len);

#endif