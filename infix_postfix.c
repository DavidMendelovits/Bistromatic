/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_postfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:49:40 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 23:43:29 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

#define MISSING_() "Error! -> missing parenthesis\n"
#define END_OP "Error! -> You need to end with an operand\n"
#define MISSING_OP "Error! -> You need to include an operator\n"

/*
** top of the stack will be one less than current position?
*/

void			redirect_operator(char op, t_op *o, t_stack **head)
{
	char			tmp;

	printf("\nfunction -> redirect_operator\n");
	printf("stack before:\n");
	print_op_stack(*o);
	if (o->sp > 0)
	{
		while (!is_empty(o) && is_priority(o->stack[o->sp - 1], op))
		{
			tmp = pop_op(o);
			push_op_queue(head, tmp);
		}
	}
	push_op(o, op);
	printf("stack after:\n");
	print_op_stack(*o);
}



int				eval_parenthesis(t_input *data, t_op *o, t_stack **stack)
{
	if (data->input[data->p] == '(')
	{
		if (data->p > 0 && !is_op(data->input[data->p - 1]))
			return ((int)write_error(MISSING_OP, sizeof(MISSING_OP)));
		push_op(o, data->input[data->p]);
	}
	else if (data->input[data->p] == ')')
	{
		if (!push_paren_contents(stack, o))
			return ((int)write_error(MISSING_(), sizeof(MISSING_())));
	}
	return (1);
}

void			init_input_struct(t_input **data, char *base, char *input)
{
	*data = (t_input *)malloc(sizeof(t_input));
	(*data)->input = input;
	(*data)->len = ft_strlen(input);
	(*data)->base = base;
	(*data)->p = 0;
	(*data)->sign = 0;
}

void			get_sign(t_input **data)
{
	if ((*data)->input[(*data)->p] == '-')
	{
		(*data)->sign = ((*data)->sign) ? 0 : 1;
	}
}

void			eval_op(t_input **data, t_op *o, t_stack **stack)
{
	if (is_unary_negative((*data)->input, (*data)->p, (*data)->base)
		|| is_unary_positive((*data)->input, (*data)->p, (*data)->base))
	{
		get_sign(data);
	}
	else if (is_nbr((*data)->input[(*data)->p], (*data)->base))
	{
			extract_operand(stack, (*data)->input, &(*data)->p, (*data)->base);
	}
	else if (is_op((*data)->input[(*data)->p]))
		redirect_operator((*data)->input[(*data)->p], o, stack);	
	else if ((*data)->input[(*data)->p] == '(' || (*data)->input[(*data)->p] == ')')
	{
		if (!eval_parenthesis(*data, o, stack))
		{
			write_error(SYNTAX_ERROR, sizeof(SYNTAX_ERROR));
			g_err = 1;
		}
	}
	(*data)->p += 1;
}

t_stack			*infix_postfix(char *input_, char *base)
{
	t_stack			*stack;
	t_op			op;
	t_input			*data;

	init_input_struct(&data, base, input_);
	init_op_stack(&op);
	stack = NULL;
	while (data->input[data->p])
	{
		if (g_err)
			return (NULL);
		printf(" ->-> %c\n", data->input[data->p]);
		eval_op(&data, &op, &stack);
		if (stack)
			print_output_stack(stack);
	}
	if (is_op(data->input[data->p - 1]))
		return (write_error(END_OP, sizeof(END_OP)));
	if (!empty_operator_stack(&op, &stack) || op.is_parenthesis < 0)
		return (write_error(MISSING_(), sizeof(MISSING_())));
	return (stack);
}
