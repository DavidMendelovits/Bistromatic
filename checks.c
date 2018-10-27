/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 14:57:38 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 16:29:14 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int					is_op(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '^')
	{
		b_printf("char %c is_op\n", c);
		return (1);
	}
	return (0);
}

int					is_nbr(char c, char *base)
{
	int				bp;

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

int					is_priority(char a1, char a2)
{
	printf("\nfunction -> is_priority\n");
	if ((a1 == '^' || a1 == '#') && a2 != '(')
	{
		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	else if ((a1 == '*' || a1 == '/' || a1 == '%') && (a2 != '^' && a2 != '('))
	{
		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	else if ((a1 == '+' || a1 == '-') && (a2 == '+' || a2 == '-'))
	{
		printf("%c is priority over %c\n", a1, a2);
		return (1);
	}
	printf("%c isn't priority over %c\n", a1, a2);
	return (0);
}
