#include "bistromatic.h"

void                push_op_stack(t_op *op, int c)
{
    b_printf("\nfunction -> push_op_stack\n");
    b_printf("op = %d\n", c);
    op->stack[op->sp] = c; 
	b_printf("op pushed to stack = %i @ op->stack[%d]\n", c, op->sp);
	op->sp += 1;
}

void				push_nbr_front(t_stack **head, char *input, int *p, char *base)
{
	t_stack			*new;

	b_printf("\nfunction -> push_nbr_front\n");
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = (void *)extract_number(input, p, base);
	b_printf("number extracted = %s\n", (char *)new->data);
	new->is_string = 1;
	new->is_op = 0;
	new->prev = NULL;
	if (*head)
	{
		b_printf("head exists\n");
		(*head)->prev = new;
        new->next = *head;
	}
	*head = new;
}

void				init_output_stack(t_stack *output)
{
	b_printf("\nfunction -> init_output_stack\n");
	output->next = NULL;
	output->prev = NULL;
	output->is_string = 0;
	output->is_op = 0;
}

void				push_op_front(t_stack **head, t_op *operators)
{
	t_stack			*new;

	b_printf("function -> push_op_front\n");
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = malloc(sizeof(int));
	new->data = (void *)(intptr_t)operators->stack[--operators->sp];
	operators->stack[operators->sp--] = nil;
	new->is_string = 0;
	new->is_op = 1;
	if (*head)
	{
		b_printf("head exists\n");
		(*head)->prev = new;
        new->next = *head;
	}
	*head = new;
}
