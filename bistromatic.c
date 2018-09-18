#include "bistromatic.h"

int                 bistromatic(char *base, int input_size)
{
    printf("base: %s\ninput_size: %d", base, input_size);
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
