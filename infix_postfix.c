#include "bistromatic.h"

void            init_op_stack(t_op *op)
{
    int         i;

    i = 0;
    while (i < 1024)
    {
        op->stack[i] = '\0';
        i += 1;
    }
    op->sp = 0;
}

void            push_operand(t_stack **head, char *operand)
{
    t_stack         *tmp;

    tmp = (t_stack *)malloc(sizeof(t_stack));
    tmp->data = operand;
    tmp->is_string = 1;
    tmp->is_op = 0;
    tmp->prev = NULL; 
    tmp->next = (*head);
    if ((*head))
    {
        (*head)->prev = tmp;
    }
    (*head)->new;
}

void            pull_operand(t_stack **head, char *input, int *p, char *base)
{
    int             begin;

    begin = *p;
    while (is_nbr(input[*p]))
    {
        *p += 1;
    }
    *p -= 1;
    push_operand(head, ft_strdup_range(input, begin, *p));
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
            redirect_operator(input[ip], &op);
        }
        else if (is_nbr(input[ip]))
        {
            pull_operand(&stack, input, &ip, base);
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
