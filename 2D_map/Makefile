# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 17:10:09 by zanejar           #+#    #+#              #
#    Updated: 2023/05/20 06:59:07 by zanejar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINK = -lmlx -framework OpenGL -framework AppKit

SRC =	main.c player.c map.c hooks.c ray_casting.c movement.c \
		casting_utils.c walls_rendering.c

HEADER = header.h

OBJ = $(SRC:.c=.o)

RM = rm -rf

all :		$(NAME) 

$(NAME):	$(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(LINK) $(OBJ) -o $(NAME)

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re 