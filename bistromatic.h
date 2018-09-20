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
void					extract_operand(t_stack **head, char *input, int *p, char *base);
void					push_operand(t_stack **head, char *operand);
void					init_op_stack(t_op *o);
int						empty_operator_stack(t_op *o, t_stack **head);
int						is_empty(t_op *o);
int						is_priority(char a1, char a2);
void					push_parent_contents(t_stack **head, t_op *o);
char					*ft_chardup(char _c);

void                	print_output_stack(t_stack *output);
void                	print_op_stack(t_op operators);

void                    solve(char *base, char *input, int input_len);
int                     bistromatic(char *base, int input_size);

#endif
