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
#define OP "^*/+-"

typedef struct			s_stack
{
	int				stack[1024];
	int				sp;
}						t_stack;

int                     bistromatic(char *base, int input_size);
char                    *read_input(char *base, int input_size);

#endif
