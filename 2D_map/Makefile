# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 17:10:09 by zanejar           #+#    #+#              #
#    Updated: 2023/05/23 08:41:25 by wiessaiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
    
CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINK = -lmlx -framework OpenGL -framework AppKit

SRC =	casting_utils.c hooks.c main.c map.c movement.c player.c ray_casting.c walls_rendering.c  utils_merging.c   \
							../parsing/check_map_game.c \
							../parsing/colors_parsing.c \
							../parsing/fill_map.c \
							../parsing/ft_split.c  \
							../parsing/get_next_line.c \
							../parsing/libft_utils.c  \
							../parsing/new_map.c \
							../parsing/parse_fill.c \
							../parsing/parsing_utils.c \
							../parsing/parsing.c \
							../parsing/split2.c \
							../parsing/texters_parsing.c \
							../parsing/the_new_map.c \

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