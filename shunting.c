/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 21:39:30 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:20 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct stack
{
	int				data;
	struct stack	*next;
}				stack;

void	push(stack **head, int value)
{
	stack	*node;

	node = malloc(sizeof(stack));
	if (node == NULL)
		return ;
	else
	{
		node->data = value;
		node->next = *head;
		*head = node;
	}
}

int		need(char op)
{
	if (op == '+' || op == '-' || op == '/' || op  == '*' || op == '%'
			|| op == '^')
		return (2);
	else
		printf("\n\ninvalid operand\n\n");
	return (1);
}

int		checknr(char *number)
{
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (0);
		number++;
	}
} /*convert to check for matching numerical symbols in Bistromatic*/

int		main(int argc, char **argv)
{
	int		i;
	int		temp;
	int		stack_size;
	char	*token;
	char	*endptr;
	char	*op;

	if (argc == 1)
		return (0);
	temp = 0;
	stack_size = 0;
	i = 0;
	while (++i < argc)
	{
		token = argv[i];
		if (checknr(token))
		{
			temp = atoi(token);
			push(&head, temp);
			stack_size++;
		}
		else /* we have an op */
		{
			if (strlen(token) != 1)
				return (0); /*actually not an op*/
			op = token[0];
			if (stack_size < need(op))
			{
				printf("too few args on stack.\n");
				return (0);
			}

		


	

