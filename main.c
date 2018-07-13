#include "libft/libft.h"
#include "bistromatic.h"

int     main(int argc, char **argv)
{
    int     num_len;

    if (argc != 3)
        return (0);
    num_len = ft_atoi(argv[2]);
    begin_parse(argv[1], num_len);
    return (0);
}
