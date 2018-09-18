NAME = calc

CFLAGS = -Wall -Wextra -Werror

SRC = bistromatic.c

OBJ = bistromatic.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC) -I libft/ -I $(NAME)
	@gcc $(OBJ) libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
