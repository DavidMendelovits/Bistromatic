#ifndef BISTROMATIC_H
# define BISTROMATIC_H

typedef struct  s_equ
{
    char            *ptr_a;
    char            *ptr_b;
    char            *op;
    struct s_equ    *next;
}               t_equ;

typedef struct  s_result
{
    char            *digit;
    char            *overflow;
    struct s_result *next;
}               t_result;

char    *read_expression(int expr_size);
int     begin_parse(char *base, int expr_size);
int     ft_atoi(const char *str);     

#endif
