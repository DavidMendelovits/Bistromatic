//#include "bistromatic.h"
#include "libft/libft.h"
#include <stdio.h>

void            pad_string_zero(char **str, int pad, char zero)
{
    printf("->%s\n", __func__);
    char            *tmp;
    char            *_free;
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
    while ((*str)[sp])
    {
        tmp[tp] = (*str)[sp];
        tp += 1;
        sp += 1;
    }
    tmp[tp] = '\0';
    _free = *str;
    free(_free);
    *str = tmp;
}

int             get_num(char n, char *base)
{

}

char            operate(char _a, char _b, char *base, int *carry)
{
    int         a;
    int         b;
    int         c;
    char        _c;
    int         base_len;

    a = get_num(_a, base);
    b = get_num(_b, base);
    c = a + b;
    base_len = ft_strlen(base);
    if (c > base_len)
    {
        *carry = c % base_len;
        c /= base_len;
    }
    _c = base[c];
    return (_c);
}

char            *add(char *o1, char *o2, char *base)
{
    char        *sum;
    char        extra[1024];
    int         p;
    int         sp;
    int         carry;
    
    p = ft_strlen(o1) - 1;
    sum = (char *)ft_memalloc(sizeof(char) * (p + 2));
    sp = 0;
    while (p >= 0)
    {
        sum[sp] = operate(o1[p], o2[p], base, &carry);
    }
    return (sum);
}

char            *addition(char *o1, char *o2, char *base)
{
    printf("->%s\n", __func__);
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
    printf("%s\n%s\n", o1, o2, base);
    sum = add(o1, o2, base);
    return (NULL);
}

int             main(int argc, char **argv)
{
    if (argc == 3)
    {
        addition(ft_strdup(argv[1]), ft_strdup(argv[2]), "0123456789");
    }
    return (0);
}
