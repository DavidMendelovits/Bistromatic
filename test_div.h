/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_div.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:21:07 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/19 13:43:13 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#define FUNC() printf("->%s\n", __func__)

typedef struct      s_mult
{
    int             *num;
    int             p;
    int             len;
}                   t_mult;

char			get_dif(char _a, char _b, char *base, int *borrow);

void			swap_strings(char **a, char **b);
char			*subtract(char *o1, char *o2, char *base);	
char			*subtraction(char *o1, char *o2, char *base);
void            pad_string_zero(char **str, int pad, char zero);
int             get_num(char n, char *base);

char            *trim_zeros(char *num, char *base);
char            operate(char _a, char _b, char *base, int *carry);
char            *add(char *o1, char *o2, char *base);
char            *addition(char *o1, char *o2, char *base);
char			*division_by_int(char *numerator, int denominator, char *base);
char			*do_division(char *num, char *denom, char *base);
char                *multiplication(char *_o1, char *_o2, char *base);
char                *read_r_product(int *_prod, int len, char *base, int sign);
int                *multiply(t_mult *o1, t_mult *o2, char *base);
void                iterate_multiply(int **prod, t_mult *o1, t_mult *o2);
void                init_o(t_mult *o, char *_o, char *base);
