NAME = calc
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = main.c parse.c ft_helpers.c
OUT = main.o parse.o ft_helpers.o

all: $(NAME)

$(NAME):
		@$(CC) $(SRCS) -o $(NAME)

clean:
		/bin/rm -f $(OUT)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

