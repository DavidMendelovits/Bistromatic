#include "bistromatic.h"

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

    tmp = (t_stack *)malloc(sizeof(t_stack));
    tmp->data = operand;
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
}

void			push_op_queue(t_stack **head, char op)
{
	t_stack			*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->data = ft_strdup(&op);
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

void			push_paren_contents(t_stack **head, t_op *o)
{
	char			tmp;

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
	if (a1 == '^' && a2 != '^')
	{
		return (1);
	}
	else if ((a1 == '*' || a1 == '/' || a1 == '%' ) && (a2 == '+' || a2 == '-'))
	{
		return (1);
	}
	return (0);
}
/*
** top of the stack will be one less than current position?
*/
void            redirect_operator(char op, t_op *o, t_stack **head)
{
    char			tmp;

	if (o->sp == 0 && o->stack[o->sp] == '\0')
    {
        push_op(o, op);
    }
	else
	{
		while (is_full(o) && is_priority(o->stack[o->sp - 1], op))
		{
			tmp = pop_op(o);
			push_op_queue(head, tmp);
		}
		push_op(o, op);
	}
}

t_stack         *infix_postfix(char *input, char *base)
{
    t_stack         *stack;
    t_op            op;
    int             ip;

    init_op_stack(&op);
    ip = 0;
    while (input[ip])
    {
        if (is_operator(input[ip]))
        {
            redirect_operator(input[ip], &op, &stack);
        }
        else if (is_nbr(input[ip]))
        {
            extract_operand(&stack, input, &ip, baseo);
        }
        else if (input[ip] == '(')
        {
            push_op(&op, input[ip]);
        }
        else if (input[ip] == ')')
        {
            push_paren_contents(&stack, &op)
        }
        ip += 1;
    }
    return (stack);
}
