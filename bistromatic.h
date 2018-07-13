#ifndef BISTROMATIC_H
# define BISTROMATIC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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

int		is_op(char c);
char	*parse_expr(char *expr, char *base);
int		is_valid_num(char c, char *base);
void	display_nbr_origin(char *base);
char    *read_expression(int expr_size);
int     begin_parse(char *base, int expr_size);
int     ft_atoi(const char *str);     
char	*ft_strdup(const char *s1);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(const char *str);

#endif
