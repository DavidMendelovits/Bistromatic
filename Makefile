NAME = calc
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = main.c parse.c ft_helpers.c eval_expr.c
OUT = main.o parse.o ft_helpers.o eval_expr.o

all: $(NAME)

$(NAME):
		@$(CC) $(SRCS) -o $(NAME)

clean:
		/bin/rm -f $(OUT)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

