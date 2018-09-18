#include "bistromatic.h"

int                 is_valid_char(char *base, char _char)
{
	int						i;

	b_printf("\nfunction -> is_valid_char\n");
	b_printf("char = %c\n", _char);
	i = 0; 
    if (_char == '(' || _char == ')' || _char == '+' || _char == '-' ||
        _char == '/' || _char == '*' || _char == '%' || _char == '^')
    {
		b_printf("%c is valid char\n", _char);
        return (1);
    }
    while (base[i])
    {
        if (_char == base[i])
        {
			b_printf("%c is valid char\n", _char);
            return (1);
        }
        b_printf("base = %c\n", base[i]);
        i += 1;
    }
	b_printf("%c isn't valid char\n", _char);
    return (0);
}

char                *read_input(char *base, int input_size)
{
    char                *input;
    char                buffer[1024];
    int                 bp;

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
