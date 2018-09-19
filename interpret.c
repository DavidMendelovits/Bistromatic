#include "bistromatic.h"

int					extract_operator(char c)
{
    b_printf("function -> extract operator (%c)\n", c);
	if (c == '(' || c ==')')
	{
		return (parenthesis);
	}
	else if (c == '^')
	{
		return (exponent);
	}
	else if (c == '*')
	{
		return (multiplication);
	}
	else if (c == '/')
	{
		return (division);
	}
	else if (c == '%')
	{
		return (mod);
	}
	else if (c == '+')
	{
		return (addition);
	}
	else if (c == '-')
	{
		return (subtraction);
	}
	return (-1);
}

char				*extract_number(char *input, int *p, char *base)
{
	int				begin;
	char			*number;

    b_printf("\nfunction -> extract_number\n");
	begin = *p;
	while (is_nbr(input[*p], base))
	{
		*p += 1;
	}
	*p -= 1;
	number = ft_strdup_range(input, begin, *p);
	return (number);
}
/*
void				solve(char *base, char *input, int input_len)
{
	t_stack			*output;
    t_op            operators;
	int				ip;
    int             op_code;

	b_printf("function -> solve\n");
	operators.sp = 0;
	ip = 0;
	input_len += 1;
    output = NULL;
//  output = malloc(sizeof(t_stack));	
//	init_output_stack(output);
    while (input[ip])
	{
		if (is_op(input[ip]))
		{
			b_printf("input[%d] is operator...\n", ip);
            b_printf("operators.sp = %d\n", operators.sp);
			op_code = extract_operator(input[ip]);
            if (operators.sp == 0  || is_priority(op_code, operators.stack[operators.sp - 1]))
			{	
				push_op_stack(&operators, op_code);
			}
			else
			{
				push_op_front(&output, &operators);
				push_op_stack(&operators, op_code);
			}
			print_op_stack(operators);
		}
		else if (is_nbr(input[ip], base))
		{
			b_printf("input[%d] is number...\n", ip);
			push_nbr_front(&output, input, &ip, base);
            print_output_stack(output);
		}
		else if (is_parenthesis(input[ip]))
		{
			b_printf("input[%d] is parenthesis\n");
            op_code = extract_operator(input[ip]);
			push_op_stack(&operators, op_code);
		}
        ip += 1;
	}
    if (operators.sp)
    {
        push_op_front(&output, &operators);
    }
    print_op_stack(operators);
    print_output_stack(output);
}
*/

void                redirect_op(char *input, int ip, t_op *op, t_stack *output)
{
    int             op_code;

	op_code = extract_operator(input[ip]);
    while (op->sp > 0 && is_priority(op->stack[op->sp - 1], op_code))
	{
		push_op_front(&output, op);
	}
	push_op_stack(op, op_code);
	print_op_stack(*op);
	/*
	b_printf("input[%d] is operator...\n", ip);
    b_printf("op.sp = %d\n", op->sp);
    if (op->sp == 0  || is_priority(op_code, op->stack[op->sp - 1]))
	{	
		push_op_stack(op, op_code);
	}
	else
	{
		push_op_front(&output, op);
		push_op_stack(op, op_code);
	}*/
	print_op_stack(*op);
}

//void				shunting_yard(t_stack *output, t_op *operators, t_input *input)

void				init_op_stack(t_op *op)
{
	int			i;

	op->sp = 0;
	i = 0;
	while (i < 1024)
	{
		op->stack[i] = nil;
		i += 1;
	}
}

void				solve(char *base, char *input, int input_len)
{
	t_stack			*output;
    t_op            operators;
	int				ip;
    int             op_code;
    int             priority;

	b_printf("function -> solve\n");
	init_op_stack(&operators);
	ip = 0;
	                input_len += 1;
    output = NULL;
    priority = 0;
    while (input[ip])
	{
		if (is_op(input[ip]))
		{
		    redirect_op(input, ip, &operators, output);	
        }
		else if (is_nbr(input[ip], base))
		{
			b_printf("input[%d] is number...\n", ip);
			push_nbr_front(&output, input, &ip, base);
            print_output_stack(output);
		}
		else if (is_parenthesis(input[ip]))
		{
            if (priority >= 1 && input[ip] == ')')
            {
      //          push_priority(&operators, &output);
                priority -= 1;
            }
			b_printf("input[%d] is parenthesis\n");
            op_code = extract_operator(input[ip]);
			push_op_stack(&operators, op_code);
            priority += 1;
		}
        ip += 1;
	}
    if (operators.sp)
    {
        push_op_front(&output, &operators);
    }
    print_op_stack(operators);
    print_output_stack(output);
}

