#include "bistromatic.h"

void                init_o(t_mult *o, char *_o, char *base)
{
    FUNC();
    int             i;

    o->len = ft_strlen(_o);
    o->p = 0;
    o->num = (int *)ft_memalloc(sizeof(int) * (o->len));
    i = o->len - 1;
    while (i >= 0 && _o[i] != '-')
    {
        o->num[o->p] = get_num(_o[i], base);
        i -= 1;
        o->p += 1;
    }
    o->p = 0;
    for (i = 0; i < o->len; i++)
        printf("%d ", o->num[i]);
    printf("\n");
}

void                iterate_multiply(int **prod, t_mult *o1, t_mult *o2)
{
    FUNC();
    o1->p = 0;
    while (o1->p < o1->len)
    {
        (*prod)[o1->p + o2->p] += o1->num[o1->p] * o2->num[o2->p];
        o1->p += 1;
    }
    for (int i = 0; i < (o1->len + o2->len); i += 1)
        printf("%d ", (*prod)[i]);
    printf("\n");
}

int                *multiply(t_mult *o1, t_mult *o2, char *base)
{
    FUNC();
    int             *product;
    int             radix;
    int             tmp;
    int             i;

    product = (int *)ft_memalloc(sizeof(int) * (o1->len + o2->len));
    radix = ft_strlen(base);
    while (o2->p < o2->len)
    {
        iterate_multiply(&product, o1, o2);
        o2->p += 1;
    }
    i = 0;
    while (i < (o1->len + o2->len))
    {
        tmp = product[i] / radix;
        product[i] %= radix;
        product[i + 1] += tmp;
        i += 1;
    }
    return (product);
}

char                *read_r_product(int *_prod, int len, char *base, int sign)
{
    FUNC();
    char            *prod;
    int             i;
    int             p;

    prod = (char *)ft_memalloc(sizeof(char) * (len + 1));
    i = 0;
    p = len - 1;
    if (sign == -1)
    {
        prod[i++] = '-';
    }
    while (_prod[p] == 0)
        p -= 1;
    while (p >= 0)
    {
        prod[i] = base[_prod[p]];
        p -= 1;
        i += 1;
    }
    return (prod);
}

char                *multiplication(char *_o1, char *_o2, char *base)
{
    FUNC();
    t_mult          o1;
    t_mult          o2;
    int             *r_product;
    char            *product;
    int             sign;

    if ((_o1[0] == '-' && _o2[0] == '-') || (_o1[0] != '-' && _o2[0] != '-'))
    {
        sign = 1;
    }
    else if (_o1[0] == '-' || _o2[0] == '-')
    {
        sign = -1;
    }
    init_o(&o1, _o1, base);
    init_o(&o2, _o2, base);
    printf("%s * %s\n", _o1, _o2);
    r_product = multiply(&o1, &o2, base);
    product = read_r_product(r_product, o1.len + o2.len, base, sign);
    return (product);
}
