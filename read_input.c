#include "bistromatic.h"

int                 is_valid_char(char *base, char _char)
{
    if (is_op(_char) || is_nbr(_char, base) || _char == '(' || _char == ')')
    {
        return (1);
    }
    return (0);
}

char                *read_input(char *base, int input_size)
{
    char                *input;
    char                *buffer;
    int                 bp;

	buffer = ft_memalloc(sizeof(char) * (input_size+1));
	b_printf("function -> read_input\n");
    input = NULL;
    bp = 0;
    while (read(0, &buffer[bp], 1))
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
    b_printf("\nEND READ\n\n\n");
    return (input);
}
