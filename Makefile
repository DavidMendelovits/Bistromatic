# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 19:22:55 by dmendelo          #+#    #+#              #
#    Updated: 2018/09/19 19:23:34 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc

CFLAGS = -Wall -Wextra -Werror

SRC = bistromatic.c checks.c read_input.c print_functions.c infix_postfix.c \
	  helper_functions.c queue.c stack.c

OBJ = bistromatic.o checks.o read_input.o print_functions.o infix_postfix.o \
	  helper_functions.o queue.o stack.o

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
