/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 00:47:33 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/13 01:24:03 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*parse_expr(char *expr, char *base)
{
	int		i;
	int		j;

	i = -1;
	while (expr[++i] != '0')
	{
		if (expr[i] == ' ')
			i++;
		if (expr[i] == '(' || expr[i] == ')')
		{
			printf(CYN "%c", expr[i]);
			continue ;
		}
			if (is_op(expr[i]))
		{
			printf(WHT "%c", expr[i]);
			continue ;
		}
		if (is_valid_num(expr[i], base))
		{
			printf(BLU "%c", expr[i]);
			continue ;
		}
	}
	return (expr);
}

int		is_op(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	else
		return (0);
}
/*consider changing to a macro?*/

int		is_valid_num(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}
