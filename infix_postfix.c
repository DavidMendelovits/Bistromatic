/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_postfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:49:40 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/15 18:51:06 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

#define MISSING_() "Error! -> missing parenthesis\n"

int				is_priority(char a1, char a2)
{
	printf("\nfunction -> is_priority\n");
	if ((a1 == '^' || a1 == '#')  && a2 != '(')
	{
		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	else if ((a1 == '*' || a1 == '/' || a1 == '%' ) && (a2 != '^' && a2 != '('))
	{

		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	else if ((a1 == '+' || a1 == '-') && (a2 == '+' || a2 == '-'))	
	{
		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	printf("%c isn't priority over %c\n", a1, a2);
	return (0);
}

/*
** top of the stack will be one less than current position?
*/
void            redirect_operator(char op, t_op *o, t_stack **head)
{
    char			tmp;

	printf("\nfunction -> redirect_operator\n");
	if (o->sp > 0)
	{
		while (!is_empty(o) && is_priority(o->stack[o->sp - 1], op))
		{
			tmp = pop_op(o);
			push_op_queue(head, tmp);
		}
	}
	push_op(o, op);
}

int				is_unary_negative(char *input, int p, char *base)
{
	if (p == 0 && input[p] == '-')
	{
		return (1);
	}
	else if (input[p] == '-' && ((input[p - 1] == ')')
			|| (is_op(input[p - 1]) && is_nbr(input[p + 1], base))))
	{
		return (1);
	}
	return (0);
}

int				is_unary_positive(char *input, int p, char *base)
{
	if (p == 0 & input[p] == '+')
	{
		return (1);
	}
	else if (input[p] == '+' && ((input[p - 1] == ')')
			|| (is_op(input[p - 1]) && is_nbr(input[p + 1], base))))
	{
		return (1);
	}
	return (0);
}
/*
void			extract_negative_operand(t_stack **head, char *input, int *p, char *base)
{
	FUNC();
	int				begin;

	begin = *p;
	*p += 1;
	while (is_nbr(input[*p], base))
	{
		*p += 1;
	}
	*p -= 1;
	push_operand(head, ft_strdup_range(input, begin, *p));
}
*/
t_stack         *infix_postfix(char *input, char *base)
{
    t_stack         *stack;
    t_op            op;
    int             ip;

    printf("\nfunction -> infix_postfix\n");
	init_op_stack(&op);
    ip = 0;
	stack = NULL;
    while (input[ip])
    {
		printf("-------------input[%d] = %c\n", ip, input[ip]);
        if (is_op(input[ip]))
        {
			if (is_unary_negative(input, ip, base))
				redirect_operator('#', &op, &stack);
			else if (is_unary_positive(input, ip, base))
				redirect_operator('!', &op, &stack);
			else
            	redirect_operator(input[ip], &op, &stack);
        }
        else if (is_nbr(input[ip], base))
        {
            extract_operand(&stack, input, &ip, base);
        }
        else if (input[ip] == '(')
        {
            push_op(&op, input[ip]);
        }
        else if (input[ip] == ')')
        {
            if (!push_paren_contents(&stack, &op))
			{
				write(2, MISSING_(), ft_strlen(MISSING_()));
				return (NULL);
			}
        }
        ip += 1;
		if (stack)
			print_output_stack(stack);
    }
	if (!empty_operator_stack(&op, &stack))
	{
		write(2, MISSING_(), ft_strlen(MISSING_()));
		return (NULL);
	}
    return (stack);
}
