/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:21:40 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 23:38:09 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void			push_operand(t_stack **head, char *operand)
{
	t_stack			*tmp;

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
	t_stack			*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->data = ft_chardup(op);
	printf("op (%c) extracted to tmp->data (%s)\n", op, tmp->data);
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

void			extract_operand(t_stack **head, char *input, int *p, char *base)
{
	int				begin;
	int				sign;
	char			*operand;

	sign = 0;
	if (input[*p] == '-')
	{
		while(input[*p] == '-')
		{

			sign = (sign) ? 0 : 1;
			printf("sign? %d\n", sign);
			printf("input[%d] = %c\n", *p, input[*p]);
			*p += 1;
		}
	}
	begin = *p;
	while (is_nbr(input[*p], base))
	{
		*p += 1;
	}
	*p -= 1;
	operand = ft_strdup_range(input, begin, *p);
	if (sign)
		prepend_negative(&operand);
	push_operand(head, operand);
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
