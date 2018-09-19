NAME = calc

CFLAGS = -Wall -Wextra -Werror

SRC = bistromatic.c checks.c read_input.c print_functions.c infix_postfix.c 

OBJ = bistromatic.o checks.o read_input.o print_functions.o infix_postfix.o

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
