/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:14:12 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 17:00:40 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void			init_op_stack(t_op *o)
{
	int				i;

	o->is_parenthesis = 0;
	i = 0;
	while (i < 1024)
	{
		o->stack[i] = '\0';
		i += 1;
	}
	o->sp = 0;
}

void			push_op(t_op *o, char op)
{
	printf("\nfunction -> push_op\n");
	o->stack[o->sp] = op;
	o->sp += 1;
}

char			pop_op(t_op *o)
{
	char			value;

	o->sp -= 1;
	value = o->stack[o->sp];
	o->stack[o->sp] = '\0';
	return (value);
}

int				is_empty(t_op *o)
{
	int				i;

	printf("\nfunction -> is_empty\n");
	i = o->sp - 1;
	printf("sp = %d\n", o->sp);
	while (i >= 0)
	{
		printf("'%c' @ %d\n", o->stack[i], i);
		if (o->stack[i])
		{
			printf("isn't empty\n");
			return (0);
		}
		i -= 1;
	}
	return (1);
}

int				empty_operator_stack(t_op *o, t_stack **head)
{
	char			tmp;

	printf("\nfunction -> empty_operator_stack\n");
	while (o->sp > 0)
	{
		tmp = pop_op(o);
		if (tmp == '(' || tmp == ')')
		{
			return (0);
		}
		push_op_queue(head, tmp);
	}
	return (1);
}
