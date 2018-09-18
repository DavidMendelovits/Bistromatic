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
    int				sp;
    struct s_stack  *next;
}						t_stack;

typedef enum e_op
{
    parenthesis,
    exponent,
    multiplication,
    division,
    addition,
    subtraction,
}
int                     is_op(char c);
int                     is_nbr(char c, char *base);
int                     is_parenthesis(char c);
void                    solve(char *base, char *input, int input_len);
int                     bistromatic(char *base, int input_size);
int                     is_valid_char(char *base, char _char);
char                    *read_input(char *base, int input_size);

#endif
