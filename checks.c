#include "bistromatic.h"

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
