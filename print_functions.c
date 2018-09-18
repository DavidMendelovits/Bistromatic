#include "bistromatic.h"

void                print_op_stack(t_op operators)
{
    b_printf("\nfunction -> print_op_stack\n");
    int             i;

    i = 0;
    while (i < operators.sp)
    {
        b_printf("stack[%d] = %i\n", i, operators.stack[i]);
        i += 1;
    }
}

void                print_output_stack(t_stack *output)
{
    static int          run = 0;
    if (run == 0)
    {
        b_printf("\nfunction -> print_output_stack\n");
        run = 1;
    }
 //   if (output->data)
    if (output->is_string)
	{
		b_printf("%s\n", (char*)output->data);
	}
	else if (output->is_op)
	{
		b_printf("%u\n", (intptr_t)output->data);
	}
	if (output->next != NULL)
    {
        output = output->next;
        print_output_stack(output);
    }
    run = 0;
}

