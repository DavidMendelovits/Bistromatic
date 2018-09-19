/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 07:50:45 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/19 13:09:22 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int                 bistromatic(char *base, int input_size)
{
    char                *input;
    t_stack             *stack;

    input = read_input(base, input_size);
    if (!input)
    {
        write(2, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR));
        return (0);
    }
    stack = infix_postfix(input, base);
    if (!stack)
    {
        write(2, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR));
        return (0);
    }
//    eval(stack);
    return (1);
}

int                 main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (!bistromatic(argv[1], ft_atoi(argv[2])))
        {
            return (1);
        }
    }
    return (0);
}
