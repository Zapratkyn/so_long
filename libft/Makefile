# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:58:07 by gponcele          #+#    #+#              #
#    Updated: 2022/10/19 13:22:16 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					=	ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c get_next_line.c \
								get_next_line_utils.c ft_errors.c ft_putendl_fd.c ft_printf.c ft_print_char.c \
								ft_print_nbr.c ft_print_others.c
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