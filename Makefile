# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:22:43 by gponcele          #+#    #+#              #
#    Updated: 2022/10/19 13:10:41 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long
SRC						=	so_long.c get_info.c so_long_utils.c
LIBFT					=	./libft/libft.a
CC						=	gcc
RM						=	rm -rf
INCLUDES				=	-I./includes -I./MLX
CFLAGS					=	-Wall -Wextra -Werror 
OBJS					=	$(SRC:.c=.o)
LMLX					=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRC) $(LMLX) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re