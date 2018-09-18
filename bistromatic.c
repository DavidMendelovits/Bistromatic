/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 07:50:45 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/18 13:09:52 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int                 is_valid_char(char *base, char _char)
{
	int						i;

	i = 0; 
    if (_char == '(' || _char == ')' || _char == '+' || _char == '-' ||
        _char == '/' || _char == '*' || _char == '%')
    {
        return (1);
    }
    while (base[i])
    {
        if (_char == base[i])
        {
            return (1);
        }
        b_printf("base = %c\n", base[i]);
        i += 1;
    }
    return (0);
}

char                *read_input(char *base, int input_size)
{
    char                *input;
    char                buffer[1024];
    int                 bp;

    input = NULL;
    bp = 0;
    while (read(2, &buffer[bp], 1))
    {
        if (!is_valid_char(base, buffer[bp]))
        {
            break ;
        }
        bp += 1;
        if (bp >= input_size)
        {
            break ;
        }
    }
    if (bp == input_size)
    {
        input = ft_strdup(buffer);
        printf("input = %s\n", input);
    }
    return (input);
}

int                 is_priority(int op1, int op2)
{
    if (op1 == parenthesis)
    {
        return (1);
    }
    else if (op1 == multiplication && op2 >= division)
    {
        return (0);
    }
    else if (op1 == division && op2 >= division)
    {
        return (0);
    }
    else if (op1 == addition && op2 >= subtraction)
    {
        return (0);
    }
    else if (op1 == subtraction && op2 >= subtraction)
    {
        return (0);
    }
    return (1);
}

int                 is_op(char c)
{
    b_printf("function -> char %c is_op\n", c);
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
    {
        return (1);
    }
    return (0);
}

int                 is_nbr(char c, char *base)
{
    int             bp;

    bp = 0;
    while (base[bp])
    {
        if (base[bp] == c)
        {
            return (1);
        }
        bp += 1;
    }
    return (0);
}

int                 is_parenthesis(char c)
{
    if (c == '(' || c == ')')
    {
        return (1);
    }
    return (0);
}


void                push_op_stack(t_op *op, char c)
{
	b_printf("function -> push_op_stack\n");
    op->stack[op->sp] = c; 
	b_printf("op pushed to stack = %c\n", op->stack[op->sp]);
	op->sp += 1;
}


char				*extract_number(char *input, int *p, char *base)
{
	int				begin;
	char			*number;

	begin = *p;
	while (is_nbr(input[*p], base))
	{
		*p += 1;
	}
	*p -= 1;
	number = ft_strdup_range(input, begin, *p);
	return (number);
}

void				push_nbr_front(t_stack **head, char *input, int *p, char *base)
{
	t_stack			*new;

	b_printf("function -> push_nbr_front\n");
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = (void *)extract_number(input, p, base);
	b_printf("\nnumber extracted = %s\n", (char *)new->data);
	new->is_string = 1;
	new->is_op = 0;
	new->prev = NULL;
	if (*head)
	{
		b_printf("head exists\n");
		(*head)->prev = new;
	}
	*head = new;
}

/*
void                push_nbr_output(t_stack *output, char *input, int *p, char *base)
{
	int				begin;

	b_printf("function -> push_nbr_output\n");
	begin = *p;
	while (is_nbr(input[*p], base))
	{
		*p += 1;
	}
    *p -= 1;
	output->data = ft_strdup_range(input, begin, *p);
	b_printf("number pushed to stack = %s\n", (char*)output->data);
	output->is_string = 1;
	output->next = (t_stack*)malloc(sizeof(t_stack));
	output->next->prev = output;
    b_printf("%s\n", (char*)output->next->prev->data);
	print_output_stack(output);
	output = output->next;

}
*/

void				init_output_stack(t_stack *output)
{
	b_printf("function -> init_output_stack\n");
	output->next = NULL;
	output->prev = NULL;
	output->is_string = 0;
	output->is_op = 0;
}

void                print_op_stack(t_op operators)
{
    b_printf("function -> print_op_stack\n");
    while (--operators.sp >= 0)
    {
        b_printf("%c\n", (char)operators.stack[operators.sp]);
    }
}

void                print_output_stack(t_stack *output)
{
    b_printf("function -> print_output_stack\n");
    b_printf("%s\n", (char*)output->data);
    if (output->next)
    {
        output = output->next;
        print_output_stack(output);
    }
}

void				solve(char *base, char *input, int input_len)
{
	t_stack			*output;
    t_op            operators;
	int				ip;

	b_printf("function -> solve\n");
	operators.sp = 0;
	ip = 0;
	input_len += 1;
    output = malloc(sizeof(t_stack));	
	init_output_stack(output);
    while (input[ip])
	{
		if (is_op(input[ip]))
		{
			b_printf("input[%d] is operator...\n", ip);
			push_op_stack(&operators, input[ip]);
		}
		else if (is_nbr(input[ip], base))
		{
			b_printf("input[%d] is number...\n", ip);
			push_nbr_front(&output, input, &ip, base);
			print_output_stack(output);
      //      b_printf("%s\n", (char *)output->prev->data);
		}
		else if (is_parenthesis(input[ip]))
		{
			b_printf("input[%d] is parenthesis\n");
			push_op_stack(&operators, input[ip]);
		}
        ip += 1;
	}
    print_op_stack(operators);
    print_output_stack(output);
}

int                 bistromatic(char *base, int input_size)
{
    char                *input;

    input = read_input(base, input_size);
    if (!input)
    {
        write(2, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR));
        return (0);
    }
	solve(base, input, input_size);

    


    return (1);
}

int                 main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (!bistromatic(argv[1], ft_atoi(argv[2])))
        {
            return (1);
        }
    }
    return (0);
}
