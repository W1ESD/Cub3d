SRCS = $(wildcard *.c)

CC = gcc

NAME = parsing

CFLANG = -Wall -Wextra -Werror 

OBJS = $(SRCS:.c=.o)


all: $(NAME) 

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re