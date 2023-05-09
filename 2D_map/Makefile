# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 17:10:09 by zanejar           #+#    #+#              #
#    Updated: 2023/05/03 17:13:46 by zanejar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINK = -lmlx -framework OpenGL -framework AppKit

SRC =	main.c

HEADER = cub3d.h

OBJ = $(SRC:.c=.o)

RM = rm -rf

all :		$(NAME) 

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(LINK) $(OBJ) -o $(NAME)

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re 