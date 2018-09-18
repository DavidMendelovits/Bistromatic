#include "bistromatic.h"

int                 is_valid_char(char *base, char _char)
{
    while (base)
    {
        if (_char == *base)
        {
            return (1);
        }
        b_printf("base = %c\n", *base);
        base += 1;
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

int                 bistromatic(char *base, int input_size)
{
    char                *input;

    input = read_input(base, input_size);
    if (!input)
    {
        write(2, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR));
        return (0);
    }
    


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
