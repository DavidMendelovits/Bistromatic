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

typedef struct			s_stack
{
    void            *data;
    int             is_string:1;
    int             is_op:1;
    struct s_stack  *next;
	struct s_stack	*prev;
}						t_stack;

typedef struct			s_op
{
	int				stack[1024];
	int				sp;
}						t_op;

typedef enum e_operators
{
    subtraction,
    addition,
	mod,
	division,
    multiplication,
    exponent,
    parenthesis,
}			t_operators;

int                     is_op(char c);
int                     is_nbr(char c, char *base);
int                     is_parenthesis(char c);
int						is_priority(int op1, int op2);
int                     is_valid_char(char *base, char _char);


int					    extract_operator(char c);
char                    *extract_number(char *input, int *p, char *base);

char                    *read_input(char *base, int input_size);
void					init_output_stack(t_stack *output);


void					push_nbr_front(t_stack **head, char *input, int *p, char *base);
void					push_op_stack(t_op *op, int c);
void				    push_op_front(t_stack **head, t_op *operators);

void                	print_output_stack(t_stack *output);
void                	print_op_stack(t_op operators);

void                    solve(char *base, char *input, int input_len);
int                     bistromatic(char *base, int input_size);

#endif
