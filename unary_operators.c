/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unary_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:18:01 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 23:22:49 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int				is_unary_negative(char *input, int p, char *base)
{
	if (p == 0 && input[p] == '-')
	{
		return (1);
	}
	else if (p >= 1 && input[p] == '-' && input[p - 1] == '(')
	{
		return (1);
	}
	else if (p >= 2 && input[p] == '-' && input[p - 1] == ')'
			&& is_nbr(input[p - 2], base))
	{
		return (0);
	}
	else if (input[p] == '-' && is_op(input[p - 1]))
	{
		return (1);
	}
	return (0);
}

int				is_unary_positive(char *input, int p, char *base)
{
	if (p == 0 & input[p] == '+')
	{
		return (1);
	}
	else if (input[p] == '+' && is_op(input[p - 1]))
	{
		return (1);
	}
	else if (p >= 2 && input[p] == '+' && input[p - 1] == ')'
			&& is_nbr(input[p - 2], base))
	{
		return (0);
	}
	else if (input[p] == '+' && input[p - 1] == ')')
	{
		return (1);
	}
	return (0);
}
