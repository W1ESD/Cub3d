# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 17:10:09 by zanejar           #+#    #+#              #
#    Updated: 2023/05/16 00:36:45 by zanejar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINK = -lmlx -framework OpenGL -framework AppKit

SRC =	main.c player.c map.c hooks.c rays_drawing.c movement.c casting_rays.c

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