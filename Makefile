# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:22:43 by gponcele          #+#    #+#              #
#    Updated: 2022/10/21 15:08:14 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long
SRC_MAC					=	so_long.c get_info.c so_long_utils_mac.c ft_errors.c ft_strchr_so_long.c ft_free.c \
							ft_draw.c ft_parsing.c ft_moves.c
SRC_LINUX				=	so_long.c get_info.c so_long_utils_linux.c ft_errors.c ft_strchr_so_long.c ft_free.c \
							ft_draw.c ft_parsing.c ft_moves.c \
							libft/ft_print_char.c libft/ft_print_nbr.c libft/ft_print_others.c libft/ft_printf.c \
							libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
							libft/ft_strlen.c libft/get_next_line.c libft/get_next_line_utils.c
LIBFT					=	./libft/libft.a
CC						=	gcc
RM						=	rm -rf
INCLUDES				=	-I./includes -I./MLX
CFLAGS					=	-Wall -Wextra -Werror 
OBJS_MAC				=	$(SRC_MAC:.c=.o)
OBJS_LINUX				=	$(SRC_LINUX:.c=.o)
LMLX_MAC				=	-lmlx -framework OpenGL -framework AppKit
LMLX_LINUX				=	-lmlx -lXext -lX11

all:
	@printf "Précisez le système\n."

linux: $(OBJS_LINUX)
		$(CC) $(CFLAGS) $(INCLUDES) $(SRC_LINUX) $(LMLX_LINUX) -o $(NAME)

mac: $(OBJS_MAC)
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRC_MAC) $(LMLX_MAC) -o $(NAME)

clean:
		$(RM) $(OBJS_LINUX) $(OBJS_MAC)

fclean: clean
		$(RM) $(NAME)

re: fclean linux

.PHONY: all clean fclean re