//#include "bistromatic.h"
#include "libft/libft.h"

void            *pad_string_zero(char **str, int pad, char zero)
{
    printf("->%s\n", "__func__");
    char            *tmp;
    int             sp;
    int             tp;

    sp = 0;
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + pad + 1));
    tp = 0;
    while (pad)
    {
        tmp[tp] = zero;
        pad -= 1;
        tp += 1;
    }
    while (str[sp])
    {
        tmp[tp] = (*str)[sp];
        tp += 1;
        sp += 1;
    }
    tmp[tp] = '\0';
    free(*str);
    *str = tmp;
}

char            *addition(char *o1, char *o2, char *base)
{
    printf("->%s\n", "__func__");
    int             p1;
    int             p2;
    char            *sum;

    p1 = ft_strlen(o1) - 1;
    p2 = ft_strlen(o2) - 1;
    if (p1 < p2)
    {
        pad_string_zero(&o1, p2 - p1, base[0]);
    }
    else if (p2 > p1)
    {
        pad_string_zero(&o2, p1 - p2, base[0]);
    }
    printf("%s\n%s\n", o1, o2);
    return (sum);
}

int             main(int argc, char **argv)
{
    if (argc == 2)
    {
        addition(argv[1], argv[2], "0123456789");
    }
    return (0);
}
