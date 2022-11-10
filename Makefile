# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:22:43 by gponcele          #+#    #+#              #
#    Updated: 2022/11/10 09:27:18 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long
NAME_BONUS				=	so_long_bonus
SRC_MAC					=	so_long.c get_info.c so_long_utils_mac.c ft_errors.c ft_strchr_so_long.c ft_free.c \
							ft_draw.c ft_parsing.c ft_moves.c ft_moves_utils.c ft_others.c 
SRC_LINUX				=	so_long.c get_info.c so_long_utils_linux.c ft_errors.c ft_strchr_so_long.c ft_free.c \
							ft_draw.c ft_parsing.c ft_moves.c ft_moves_utils.c ft_others.c \
							libft/ft_print_char.c libft/ft_print_nbr.c libft/ft_print_others.c libft/ft_printf.c \
							libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
							libft/ft_strlen.c libft/get_next_line.c libft/get_next_line_utils.c libft/ft_itoa.c \
							libft/ft_strcmp.c libft/ft_strjoin.c
SRC_BONUS				=	bonus/so_long_bonus.c get_info.c bonus/so_long_utils_bonus.c ft_errors.c bonus/ft_strchr_so_long_bonus.c ft_free.c \
							bonus/ft_draw_bonus.c ft_parsing.c bonus/ft_moves_bonus.c bonus/ft_moves_utils_bonus.c \
							ft_others.c bonus/ft_lose.c
LIBFT					=	./libft/libft.a
CC						=	gcc
RM						=	rm -rf
INCLUDES				=	-I./includes -I./MLX
CFLAGS					=	-Wall -Wextra -Werror 
OBJS_MAC				=	$(SRC_MAC:.c=.o)
OBJS_LINUX				=	$(SRC_LINUX:.c=.o)
OBJS_BONUS				=	$(SRC_BONUS:.c=.o)
LMLX_MAC				=	-lmlx -framework OpenGL -framework AppKit
LMLX_LINUX				=	-lmlx -lXext -lX11

all: $(NAME)

linux: $(OBJS_LINUX)
		$(CC) $(CFLAGS) $(INCLUDES) $(SRC_LINUX) $(LMLX_LINUX) -o $(NAME)

$(NAME): $(OBJS_MAC)
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRC_MAC) $(LMLX_MAC) $(MLX) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(LMLX_MAC) $(SRC_BONUS) -o $(NAME_BONUS)

clean:
		$(RM) $(OBJS_LINUX) $(OBJS_MAC) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean linux

.PHONY: all clean fclean re