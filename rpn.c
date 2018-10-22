/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:46:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 20:47:33 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char				*pop_operand(t_stack **head)
{
	char				*o;
	t_stack				*tmp;

	if (!(*head))
		return (0);
	o = ft_strdup((*head)->data);
	tmp = *head;
	*head = (*head)->next;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	free(tmp->data);
	free(tmp);
	return (o);
}

void				do_op(t_stack **head, char operator, char *base)
{
	char				*result;
	char				*o1;
	char				*o2;

	o2 = pop_operand(head);
	o1 = pop_operand(head);
	printf("\noperation:\n%s %c %s\n", o1, operator, o2);
	result = NULL;
	if (!o1 || !o2)
		return ;
	if (operator == '+')
		result = addition(o1, o2, base);
	else if (operator == '-')
		result = subtraction(o1, o2, base);
	else if (operator == '*')
		result = multiplication(o1, o2, base);
	else if (operator == '^')
		result = exponent(o1, o2, base);
	else if (operator == '/')
		result = division(o1, o2, base);
	else if (operator == '%')
		result = modulo(o1, o2, base);
	else
		result = NULL;
	if (result)
		push_operand(head, result);
	else
		g_err = 1;
}

void				do_unary(t_stack **head, char operator)
{
	char				*operand;

	operand = pop_operand(head);
	printf("operand before: %s\n", operand);
	if (operator == '#')
	{
		if (operand[0] == '-')
		{
			trim_negative(&operand);
		}
		else if (operand[0] != '-')
		{
			prepend_negative(&operand);
		}
	}
	if (operand)
	{
		printf("operand after: %s\n", operand);
		push_operand(head, operand);
	}
}

void				eval(t_stack *queue, char *base)
{
	t_stack				*operands;
	
	g_err = 0;
	while (queue->next)
		queue = queue->next;
	operands = NULL;
	while (queue)
	{
		printf("---\n%s\n---", queue->data);
		if (g_err)
		{
			write_error(SYNTAX_ERROR, sizeof(SYNTAX_ERROR));
			return ;
		}
		if (!queue->is_op && queue->is_string)
			push_operand(&operands, queue->data);
		else if (queue->is_op && (!ft_strcmp(queue->data, "#")
				|| !ft_strcmp(queue->data, "!")))
			do_unary(&operands, queue->data[0]);
		else if (queue->is_op)
			do_op(&operands, queue->data[0], base);
		queue = queue->prev;
		if (queue && queue->data)
			printf("\n%s\n", queue->data);
		if (operands)
			print_output_stack(operands);
//		print_output_stack(queue);
	}
}
