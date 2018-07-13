# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiuza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 12:51:27 by lfiuza            #+#    #+#              #
#    Updated: 2018/07/12 20:01:31 by lfiuza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc

all: $(NAME)

$(NAME):
		@gcc -g -Wall -Wextra -Werror -o $(NAME) big_num.c

clean:
		@/bin/rm -f

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
