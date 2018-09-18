#include "bistromatic.h"

int                 is_valid_char(char *base, char _char)
{
	int						i;

	i = 0; 
    if (_char == '(' || _char == ')' || _char == '+' || _char == '-' ||
        _char == '/' || _char == '*' || _char == '%')
    {
        return (1);
    }
    while (base[i])
    {
        if (_char == base[i])
        {
            return (1);
        }
        b_printf("base = %c\n", base[i]);
        i += 1;
    }
    return (0);
}

char                *read_input(char *base, int input_size)
{
    char                *input;
    char                buffer[1024];
    int                 bp;

    input = NULL;
    bp = 0;
    while (read(2, &buffer[bp], 1))
    {
        if (!is_valid_char(base, buffer[bp]))
        {
            break ;
        }
        bp += 1;
        if (bp >= input_size)
        {
            break ;
        }
    }
    if (bp == input_size)
    {
        input = ft_strdup(buffer);
        printf("input = %s\n", input);
    }
    return (input);
}

int                 is_priority(int op1, int op 2)
{
    if (op1 == parenthesis)
    {
        return (1);
    }
    else if (op1 == multiplication && op2 >= division)
    {
        return (0)
    }
    else if (op1 == division && op2 >= division)
    {
        return (0);
    }
    else if (op1 == addition && op2 >= subtraction)
    {
        return (0)
    }
    else if (op1 == subtraction && op2 >= subtraction)
    {
        return (0);
    }
    return (1);
}

int                 is_op(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
    {
        return (1);
    }
    return (0);
}

int                 is_nbr(char c, char *base)
{
    int             bp;

    bp = 0;
    while (base[bp])
    {
        if (base[bp] == c)
        {
            return (1);
        }
        bp += 1;
    }
    return (0);
}

int                 is_parenthesis(char c)
{
    if (c == '(' || c == ')')
    {
        return (1);
    }
    return (0);
}


void                push_op_stack(t_stack *op, char c)
{
    op->stack[op->sp] = c;
    op->sp += 1;
}

void                push_output_stack(t_stack *output, char c, char *base)
{
    output->stack[output->sp] = c;
    output->sp += 1;
}

void				solve(char *base, char *input, int input_len)
{
	t_stack			output;
    int             operators[1024];
	int				ip;

	operators.sp = 0;
	output.sp = 0;
	ip = 0;
	while (input[ip])
	{
		if (is_op(input[ip]))
		{
			push_op_stack(&operators, input[ip]);
		}
		else if (is_nbr(input[ip], base))
		{
            get_nbr(input, ip, base);
			push_output_stack(&output, input[ip], base);
		}
		else if (is_parenthesis(input[ip]))
		{
			push_op_stack(&operators, input[ip]);
		}
        ip += 1;
	}
}

int                 bistromatic(char *base, int input_size)
{
    char                *input;

    input = read_input(base, input_size);
    if (!input)
    {
        write(2, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR));
        return (0);
    }
	solve(base, input, input_size);

    


    return (1);
}

int                 main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (!bistromatic(argv[1], ft_atoi(argv[2])))
        {
            return (1);
        }
    }
    return (0);
}
