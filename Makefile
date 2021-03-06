# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 19:22:55 by dmendelo          #+#    #+#              #
#    Updated: 2018/10/27 13:13:15 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -g 

SRC = bistromatic.c checks.c read_input.c print_functions.c infix_postfix.c \
	  helper_functions.c queue.c stack.c rpn.c addition.c subtraction.c \
	  multiplication.c exponent.c redirections.c unary_operators.c \
	  division.c helper_functions_pt2.c modulo.c

OBJ = bistromatic.o checks.o read_input.o print_functions.o infix_postfix.o \
	  helper_functions.o queue.o stack.o rpn.o addition.o subtraction.o \
	  multiplication.o exponent.o redirections.o unary_operators.o \
	  division.o helper_functions_pt2.o modulo.o

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC) -I libft/ -I $(NAME)
	@gcc -fsanitize=address -fsanitize=undefined -g $(OBJ) libft/libft.a -o $(NAME)

clean:
	@make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
