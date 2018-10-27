/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:12:07 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 23:42:37 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SYNTAX_ERROR "Invalid Syntax\n"
#define OP "()^*/+-"
#define FUNC() b_printf("->%s\n", __func__)

unsigned int		g_err;

typedef struct			s_stack
{
    char            *data;
    int             is_string:1;
    int             is_op:1;
    struct s_stack  *next;
	struct s_stack	*prev;
}						t_stack;

typedef struct			s_op
{
	char			stack[1024];
	int				is_parenthesis;
	int				sp;
}						t_op;

typedef struct		s_input
{
	char			*input;
	int				len;
	char			*base;
	int				p;
	int				sign:1;
}					t_input;

typedef struct      s_mult
{
    int             *num;
    int             p;
    int             len;
}                   t_mult;

/*
** checks.c
*/
int                     is_op(char c);
int                     is_nbr(char c, char *base);
int						is_priority(char a1, char a2);

int					    extract_operator(char c);
char                    *extract_number(char *input, int *p, char *base);

/*
** read_input_c.
*/

char                    *read_input(char *base, int input_size);
void					init_output_stack(t_stack *output);

/*
** infix_postfix_c.
*/

t_stack					*infix_postfix(char *input_, char *base);
void					redirect_operator(char op, t_op *o, t_stack **head);
void					init_input_struct(t_input **data, char *base, char *input);
int						eval_parenthesis(t_input *data, t_op *o, t_stack **stack);
void					eval_op(t_input **data, t_op *o, t_stack **stack);

/*
** stack_c.
*/

void					push_op(t_op *o, char op);
int						empty_operator_stack(t_op *o, t_stack **head);
int						is_empty(t_op *o);
char					pop_op(t_op *o);
void					init_op_stack(t_op *o);

/*
** queue_c.
*/

void					extract_operand(t_stack **head, char *input, int *p, char *base);
void					push_operand(t_stack **head, char *operand);
void					push_op_queue(t_stack **head, char op);
int						push_paren_contents(t_stack **head, t_op *o);


/*
** print_function_c.
*/

void                	print_output_stack(t_stack *output);
void                	print_op_stack(t_op operators);

/*
** addition_c.
*/

char                    *addition(char *o1, char *o2, char *base);
char                    *add(char *o1, char *o2, char *base);
char                    operate(char _a, char _b, char *base, int *carry);
int                     get_num(char n, char *base);
void                    pad_string_zero(char **str, int pad, char zero);

/*
** subtraction_c.
*/

char                    *subtraction(char *o1, char *o2, char *base);
char                    *subtract(char *o1, char *o2, char *base);
void                    swap_strings(char **a, char **b);
char					*trim_zero_neg(char *num, char *base);
char                    get_dif(char _a, char _b, char *base, int *borrow);

/*
** multiplication_c.
*/

char                    *multiplication(char *_o1, char *_o2, char *base);
char                    *read_r_product(int *_prod, int len, char *base);
int                     *multiply(t_mult *o1, t_mult *o2, char *base);
void                    iterate_multiply(int **prod, t_mult *o1, t_mult *o2);
void                    init_o(t_mult *o, char *_o, char *base);

/*
** exponent_c.
*/

char                    *exponent(char *o, char *_power, char *base);
char                    *iterate_power(char *o, int power, char *base);

/*
** rpn_c.
*/

char                    *pop_operand(t_stack **head);
void                    eval(t_stack *queue, char *base);
void                    do_op(t_stack **head, char operator, char *base);
void					do_unary(t_stack **head, char operator);

/*
** division_c.
*/

char					*division(char *o1, char *o2, char *base);
char					*division_by_int(char *numerator, int denominator, char *base);
char					*do_division(char *num, char *denom, char *base, int modulo);
char					*guess_quotient(char *q, char *r, char *d, char *base);
char					*guess_r(char *num, char *denom, char *quotient, char *base);


char					*modulo(char *numerator, char *denominator, char *base);

/*
** redirections_c.
*/

char					*redirect_modulo(char *o1, char *o2, char *base);
char					*redirect_division(char *o1, char *o2, char *base);
char					*redirect_multiplication(char *o1, char *o2, char *base);
char					*redirect_addition(char *o1, char *o2, char *base);
char					*redirect_subtraction(char *o1, char *o2, char *base);

/*
** helper_functions_c.
*/

void					trim_negative(char **o);
void					prepend_negative(char **o);
void					trim_zeros(char **num, char *base);
void					*write_error(char *err_msg, size_t size);
char					*ft_chardup(char _c);

/*
** helper_functions_pt2.c
*/

int						is_zero(char *num, char *base);
char					*abs_value(char *num);
char					*avg(char *a, char *b, char *base);
void					increment(char **o1, char *o2, char *base);
int						compare(char *o1, char *o2, char *base);
/*
** unary_operators.c
*/
int						is_unary_negative(char *input, int p, char *base);
int						is_unary_positive(char *input, int p, char *base);

//void                    solve(char *base, char *input, int input_len);

/*
** bistromatic_c.
*/

int                     bistromatic(char *base, int input_size);


#endif
