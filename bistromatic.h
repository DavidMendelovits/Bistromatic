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

int     parse_expression(int expr_size, char *expr);
void    read_expression(int expr_size);

#endif
