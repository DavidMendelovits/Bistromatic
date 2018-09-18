#include "bistromatic.h"

int                 is_priority(int op1, int op2)
{
    b_printf("\nfunction -> is_priority\n");
    if (op1 == parenthesis)
    {
        return (1);
    }
    else if (op1 == multiplication && op2 >= mod)
    {
        return (0);
    }
    else if (op1 == division && op2 >= mod)
    {
        return (0);
    }
	else if (op1 == mod && op2 >= mod)
	{
		return (0);
	}
    else if (op1 == addition && op2 >= subtraction)
    {
        return (0);
    }
    else if (op1 == subtraction && op2 >= subtraction)
    {
        return (0);
    }
    return (1);
}

int                 is_op(char c)
{
    b_printf("\nfunction -> is_op\n");
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c =='^')
    {
        b_printf("char %c is_op\n", c);
        return (1);
    } 
	return (0);
}

int                 is_nbr(char c, char *base)
{
    int             bp;

    b_printf("\nfunction -> is_nbr\n");
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
