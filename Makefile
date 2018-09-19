NAME = calc

CFLAGS = -Wall -Wextra -Werror

SRC = bistromatic.c checks.c read_input.c print_functions.c interpret.c 

OBJ = bistromatic.o checks.o read_input.o print_functions.o interpret.o 

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC) -I libft/ -I $(NAME)
	@gcc -g $(OBJ) libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
