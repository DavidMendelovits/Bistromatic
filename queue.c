/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:21:40 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/16 18:13:14 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void            push_operand(t_stack **head, char *operand)
{
    t_stack         *tmp;

	printf("function -> push_operand\n");
    tmp = (t_stack *)malloc(sizeof(t_stack));
    tmp->data = operand;
	printf("operand = %s\n", tmp->data);
    tmp->is_string = 1;
    tmp->is_op = 0;
    tmp->prev = NULL;
    if (*head)
    {
    	tmp->next = (*head);
	 	(*head)->prev = tmp;
	}
	else
	{
		tmp->next = NULL;
	}
    (*head) = tmp;
	printf("end push_operand\n");
}

void			push_op_queue(t_stack **head, char op)
{
	printf("\nfunction -> push_op_queue\n");
	t_stack			*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->data = ft_chardup(op);
	printf("op (%c) extracted to tmp->data (%s)\n",op, tmp->data);
	tmp->is_op = 1;
	tmp->is_string = 0;
	tmp->prev = NULL;
	if (*head)
	{
		tmp->next = *head;
		(*head)->prev = tmp;
	}
	else
	{
		tmp->next = NULL;
	}
	(*head) = tmp;
}

void            extract_operand(t_stack **head, char *input, int *p, char *base)
{
	printf("\nfunction -> extract operand\n");
    int             begin;

    begin = *p;
    while (is_nbr(input[*p], base))
    {
        *p += 1;
    }
    *p -= 1;
    push_operand(head, ft_strdup_range(input, begin, *p));
}

int				push_paren_contents(t_stack **head, t_op *o)
{
	char			tmp;

	printf("\nfunction -> push_paren_contents\n");
	while (o->sp > 0 && o->stack[o->sp - 1] != '(')
	{
		printf("o->stack[%d] = %c", o->sp - 1, o->stack[o->sp - 1]);
		tmp = pop_op(o);
		push_op_queue(head, tmp);
	}
	if (o->stack[o->sp - 1] == '(')
	{
		pop_op(o);
	}
	else if (o->sp == 0)
	{
		printf("error... missing parenthesis\n");
		return (0);
	}
	return (1);
}
