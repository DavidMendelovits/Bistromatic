#include "bistromatic.h"

int                 is_valid_char(char *base, char _char)
{
	int						i;

	i = 0;
    while (base[i])
    {
        if (_char == base[i])
        {
            return (1);
        }
        b_printf("base = %c\n", base[i]);
        i += 1;
    }
    if (_char == '(' || _char == ')' || _char == '+' || _char == '-' ||
        _char == '/' || _char == '*' || _char == '%')
    {
        return (1);
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

void				solve(char *base, char *input, int input_len)
{
	t_stack			operators;
	t_stack			output;
	int				ip;

	operators.sp = 0;
	output.sp = 0;
	ip = 0;
	while (input[ip])
	{
		if (is_op(input[ip]))
		{
			push_op_value(&operators, input[ip]);
		}
		else if (is_nbr(input[ip], base))
		{
			push_nbr_value(&output, input[ip], base);
		}
		else if (is_parenthesis(input[ip]))
		{
			push_op_value(&operators, input[ip]);
		}
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
