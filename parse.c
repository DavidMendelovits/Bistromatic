#include "libft/libft.h"
#include "bistromatic.h"
#include <unistd.h>
#include <stdio.h>

int     begin_parse(char *base, int expr_size)
{
    read_expression(num_len);
    return (1);
}

char    *read_expression(int expr_size)
{
    int     ret;
    char    buf[expr_size + 1];
    
    ret = read(0, buf, expr_size);
    if (ret == -1)
    {
        printf("error, no file read");
        return (NULL);
    }
    printf("%s\n", buf);
    return (buf);
}  
