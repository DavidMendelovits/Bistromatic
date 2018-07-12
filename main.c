#include "libft/libft.h"
#include "Bistromatic.h"

int     main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    parse_expression(argv[1],argv[2]);
}
