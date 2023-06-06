# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 03:00:56 by zanejar           #+#    #+#              #
#    Updated: 2023/06/06 04:26:35 by zanejar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS = cub3D_bonus
    
CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINK = -lmlx -framework OpenGL -framework AppKit

SRC_M =	./mandatory/raycasting/textures.c \
		./mandatory/raycasting/casting_utils.c \
		./mandatory/raycasting/casting_utils2.c \
		./mandatory/raycasting/casting_utils3.c \
		./mandatory/raycasting/hooks.c \
		./mandatory/raycasting/main.c \
		./mandatory/raycasting/move.c \
		./mandatory/raycasting/move2.c \
		./mandatory/raycasting/direction_conds.c \
		./mandatory/raycasting/movement.c \
		./mandatory/raycasting/player.c \
		./mandatory/raycasting/ray_casting.c \
		./mandatory/raycasting/walls_rendering.c \
		./mandatory/raycasting/utils_merging.c \
		./mandatory/parsing/check_map_game.c \
		./mandatory/parsing/colors_parsing.c \
		./mandatory/parsing/fill_map.c \
		./mandatory/parsing/ft_split.c  \
		./mandatory/parsing/get_next_line.c \
		./mandatory/parsing/libft_utils.c  \
		./mandatory/parsing/new_map.c \
		./mandatory/parsing/parse_fill.c \
		./mandatory/parsing/parsing_utils.c \
		./mandatory/parsing/parsing.c \
		./mandatory/parsing/split2.c \
		./mandatory/parsing/texters_parsing.c \
		./mandatory/parsing/the_new_map.c \
		./mandatory/parsing/utils_parsing.c \
		./mandatory/parsing/colors_parsing_utils.c 

OBJ_M = $(SRC_M:.c=.o)

SRC_B =	./bonus/raycasting/textures.c \
		./bonus/raycasting/casting_utils.c \
		./bonus/raycasting/casting_utils2.c \
		./bonus/raycasting/hooks.c \
		./bonus/raycasting/main.c \
		./bonus/raycasting/main_funcs.c \
		./bonus/raycasting/move.c \
		./bonus/raycasting/move2.c \
		./bonus/raycasting/move3.c \
		./bonus/raycasting/render.c \
		./bonus/raycasting/map.c \
		./bonus/raycasting/direction_conds.c \
		./bonus/raycasting/movement.c \
		./bonus/raycasting/player.c \
		./bonus/raycasting/ray_casting.c \
		./bonus/raycasting/walls_rendering.c \
		./bonus/raycasting/walls_rendering2.c \
		./bonus/raycasting/utils_merging.c \
		./bonus/parsing/check_map_game.c \
		./bonus/parsing/colors_parsing.c \
		./bonus/parsing/colors_parsing_utils.c \
		./bonus/parsing/fill_map.c \
		./bonus/parsing/ft_split.c  \
		./bonus/parsing/get_next_line.c \
		./bonus/parsing/libft_utils.c  \
		./bonus/parsing/new_map.c \
		./bonus/parsing/parse_fill.c \
		./bonus/parsing/parsing_utils.c \
		./bonus/raycasting/casting_utils3.c \
		./bonus/parsing/parsing.c \
		./bonus/parsing/split2.c \
		./bonus/parsing/utils_parsing.c \
		./bonus/parsing/texters_parsing.c \
		./bonus/parsing/the_new_map.c

HEADER_M = ./mandatory/raycasting/header.h ./mandatory/parsing/parsing.h ./mandatory/parsing/macros.h 
HEADER_B = ./bonus/raycasting/header.h ./bonus/parsing/parsing.h ./bonus/parsing/macros.h 

OBJ_B = $(SRC_B:.c=.o)

RM = rm -rf

all :		$(NAME)

$(NAME):	$(OBJ_M) $(HEADER_M)
			$(CC) $(CFLAGS) $(LINK) $(OBJ_M) -o $(NAME)

bonus :		$(BONUS)

$(BONUS):	$(OBJ_B) $(HEADER_B)
			$(CC) $(CFLAGS) $(LINK) $(OBJ_B) -o $(BONUS)

clean :
			$(RM) $(OBJ_B) $(OBJ_M)

fclean :	clean
			$(RM) $(NAME) $(BONUS)

re :		fclean all

.PHONY :	all clean fclean re
