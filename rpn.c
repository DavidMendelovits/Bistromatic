#include "bistromatic.h"



void                eval(t_stack *queue, char *base)
{
    t_stack             *operands;

    while (queue->next)
    {
        queue = queue->next;
    }
    operands = NULL;
    while (queue)
    {
        if (queue->is_string)
        {
            push_operand(&operands, queue->data);
        }
        else if (queue->is_op)
        {
            do_op(&operands, queue->data[0], base);
        }
    }
}
