#ifndef BISTROMATIC_H
# define BISTROMATIC_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SYNTAX_ERROR "Invalid Syntax\n"
#define OP "()^*/+-"
#define FUNC() b_printf("->%s\n", __func__)

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
	int				sp;
}						t_op;

typedef struct      s_mult
{
    int             *num;
    int             p;
    int             len;
}                   t_mult;


int                     is_op(char c);
int                     is_nbr(char c, char *base);

int					    extract_operator(char c);
char                    *extract_number(char *input, int *p, char *base);

char                    *read_input(char *base, int input_size);
void					init_output_stack(t_stack *output);

t_stack					*infix_postfix(char *input, char *base);
void					redirect_operator(char op, t_op *o, t_stack **head);

void					push_op(t_op *o, char op);
void					push_op_queue(t_stack **head, char op);
char					pop_op(t_op *o);
void					init_op_stack(t_op *o);

void					extract_operand(t_stack **head, char *input, int *p, char *base);
void					push_operand(t_stack **head, char *operand);
char                    *pop_operand(t_stack **head);

int						empty_operator_stack(t_op *o, t_stack **head);
int						is_empty(t_op *o);
int						is_priority(char a1, char a2);
int						push_paren_contents(t_stack **head, t_op *o);
char					*ft_chardup(char _c);

void                	print_output_stack(t_stack *output);
void                	print_op_stack(t_op operators);

char                    *addition(char *o1, char *o2, char *base);
char                    *add(char *o1, char *o2, char *base);
char                    operate(char _a, char _b, char *base, int *carry);
int                     get_num(char n, char *base);
void                    pad_string_zero(char **str, int pad, char zero);

char                    *subtraction(char *o1, char *o2, char *base);
char                    *subtract(char *o1, char *o2, char *base);
void                    swap_strings(char **a, char **b);
char                    get_dif(char _a, char _b, char *base, int *borrow);

char                    *multiplication(char *_o1, char *_o2, char *base);
char                    *read_r_product(int *_prod, int len, char *base, int sign);
int                     *multiply(t_mult *o1, t_mult *o2, char *base);
void                    iterate_multiply(int **prod, t_mult *o1, t_mult *o2);
void                    init_o(t_mult *o, char *_o, char *base);

char                    *exponent(char *o, char *_power, char *base);
char                    *iterate_power(char *o, int power, char *base);
void                    eval(t_stack *queue, char *base);
void                    do_op(t_stack **head, char operator, char *base);


void                    solve(char *base, char *input, int input_len);
int                     bistromatic(char *base, int input_size);

#endif
