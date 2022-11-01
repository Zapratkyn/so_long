# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:58:07 by gponcele          #+#    #+#              #
#    Updated: 2022/11/01 15:38:42 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					=	ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c get_next_line.c \
								get_next_line_utils.c ft_putendl_fd.c ft_printf.c ft_print_char.c \
								ft_print_nbr.c ft_print_others.c ft_itoa.c ft_strjoin.c ft_strcmp.c \
								ft_strdup.c ft_bzero.c
OBJS					= 	$(SRCS:.c=.o)
CC						= 	gcc
RM						= 	rm -f
CFLAGS					= 	-Wall -Wextra -Werror
NAME					= 	libft.a

all:					$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
fclean:	clean
		$(RM) $(NAME)
re:	fclean $(NAME)
.PHONY	= all clean fclean re