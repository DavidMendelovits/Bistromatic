#include "bistromatic.h"


char                *pop_operand(t_stack **head)
{
    FUNC();
    char                *o;
    t_stack             *tmp;

    o = ft_strdup((*head)->data);
    tmp = *head;
    *head = (*head)->next;
    if (*head)
    {
        (*head)->prev = NULL;
    }
    free(tmp);
    return (o);
}

void                do_op(t_stack **head, char operator, char *base)
{
    FUNC();
    char                *result;
    char                *o1;
    char                *o2;
    //int                 result_sign;

    o2 = pop_operand(head);
    o1 = pop_operand(head);
    //result_sign = 1;
    printf("%s %c %s\n", o1, operator, o2);
    result = NULL;
    if (operator == '+' && o1[0] != '-' && o2[0] != '-')
    {
        result = addition(o1, o2, base);
    }
    else if (operator == '-' && o1[0] != '-' && o1[0] != '-')
    {
        result = subtraction(o1, o2, base);
    }
    else if (operator == '*')
    {
        result = multiplication(o1, o2, base);
    }
    else
    {
        result = NULL;
    }
    if (result)
        push_operand(head, result);
}
/*
void                push_operand(t_stack **operand, char *data)
{
    t_stack             *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->content = data;
    new->prev = NULL;
    if (*operand)
    {
        new->next = *operand;
        *operand->prev = new;
    }
    else
    {
        new->next = NULL;
        *operand = new;
    }
}
*/
void                eval(t_stack *queue, char *base)
{
    FUNC();
    t_stack             *operands;

    while (queue->next)
    {
        queue = queue->next;
    }
    operands = NULL;
    while (queue)
    {
        if (!queue->is_op && queue->is_string)
        {
            push_operand(&operands, queue->data);
        }
        else if (queue->is_op)
        {
            do_op(&operands, queue->data[0], base);
        }
        queue = queue->prev;
        if (operands)
            print_output_stack(operands);
    }
}
