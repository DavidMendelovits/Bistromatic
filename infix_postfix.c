/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_postfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:49:40 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/19 18:26:16 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

#define MISSING_() "Error! -> missing parenthesis\n"

void            init_op_stack(t_op *o)
{
    int         i;

    i = 0;
    while (i < 1024)
    {
        o->stack[i] = '\0';
        i += 1;
    }
    o->sp = 0;
}

void            push_operand(t_stack **head, char *operand)
{
    t_stack         *tmp;

	printf("function -> push_operand\n");
    tmp = (t_stack *)malloc(sizeof(t_stack));
    tmp->data = operand;
    tmp->is_string = 1;
    tmp->is_op = 0;
    tmp->prev = NULL;
    if (*head)
    {
    	tmp->next = (*head);
		printf("1\n");
	 	(*head)->prev = tmp;
    	printf("2\n");
	}
	else
	{
		tmp->next = NULL;
	}
    (*head) = tmp;
	printf("end push_operand\n");
}

char			*ft_chardup(char _c)
{
	char			*c;

	printf("\nfunction -> ft_chardup\n");
	c = malloc(sizeof(*c) * 2);
	c[0] = _c;
	c[1] = '\0';
	return (c);
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

void			push_op(t_op *o, char op)
{
	printf("\nfunction -> push_op\n");
	o->stack[o->sp] = op;
	o->sp += 1;
}

char			pop_op(t_op *o)
{
	printf("\nfunction -> pop_op\n");

	char			value;

	o->sp -= 1;
	value = o->stack[o->sp];
	o->stack[o->sp] = '\0';
	return (value);
}

void			push_paren_contents(t_stack **head, t_op *o)
{
	char			tmp;

	printf("\nfunction -> push_paren_contents\n");
	while (o->sp > 0 && o->stack[o->sp - 1] != '(')
	{
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
	}
}
int				is_priority(char a1, char a2)
{
	printf("\nfunction -> is_priority\n");
	if (a1 == '^' && a2 != '(')
	{
		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	else if ((a1 == '*' || a1 == '/' || a1 == '%' ) && (a2 != '^' || a2 != '('))
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

int             is_empty(t_op *o)
{
    int             i;

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
        if (is_op(input[ip]))
        {
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
            push_paren_contents(&stack, &op);
        }
        ip += 1;
    }
	if (!empty_operator_stack(&op, &stack))
	{
		write(2, MISSING_(), ft_strlen(MISSING_()));
		return (NULL);
	}
    return (stack);
}
