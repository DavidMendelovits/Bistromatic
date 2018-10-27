/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 13:32:13 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 21:50:23 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			*redirect_addition(char *o1, char *o2, char *base)
{
	char			*sum;

	sum = NULL;
	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		sum = addition(o1, o2, base);
		prepend_negative(&sum);
	}
	else if (o1[0] == '-' || o2[0] == '-')
	{
		if (o1[0] == '-')
		{
			trim_negative(&o1);
			sum = subtraction(o2, o1, base);
		}
		else if (o2[0] == '-')
		{
			trim_negative(&o2);
			sum = subtraction(o1, o2, base);
		}
	}
	return (sum);
}

char			*redirect_division(char *o1, char *o2, char *base)
{
	char				*quotient;

	quotient = NULL;
	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		quotient = division(o1, o2, base);
	}
	else if (o1[0] == '-' || o2[0] == '-')
	{
		if (o1[0] == '-')
		{
			trim_negative(&o1);
		}
		else if (o2[0] == '-')
		{
			trim_negative(&o2);
		}
		quotient = division(o1, o2, base);
		prepend_negative(&quotient);
	}
	return (quotient);
}

char			*redirect_subtraction(char *o1, char *o2, char *base)
{
	char			*dif;

	dif = NULL;
	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		dif = subtraction(o2, o1, base);
	}
	else if (o1[0] == '-' && o2[0] != '-')
	{
		trim_negative(&o1);
		dif = addition(o1, o2, base);
		prepend_negative(&dif);
	}
	else if (o1[0] != '=' && o2[0] == '-')
	{
		trim_negative(&o2);
		dif = addition(o1, o2, base);
	}
	return (dif);
}

char			*redirect_multiplication(char *o1, char *o2, char *base)
{
	char				*product;

	product = NULL;
	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		product = multiplication(o1, o2, base);
	}
	else if (o1[0] == '-' || o2[0] == '-')
	{
		if (o1[0] == '-')
			trim_negative(&o1);
		else if (o2[0] == '-')
			trim_negative(&o2);
		product = multiplication(o1, o2, base);
		prepend_negative(&product);
	}
	return (product);
}

char			*redirect_modulo(char *numerator, char *denominator, char *base)
{
	char			*r;

	r = NULL;
	if (numerator[0] == '-' && denominator[0] == '-')
	{
		trim_negative(&numerator);
		trim_negative(&denominator);
		r = modulo(numerator, denominator, base);
		prepend_negative(&r);
	}
	else if (numerator[0] == '-' || denominator[0] == '-')
	{
		if (numerator[0] == '-' && denominator[0] != '-')
		{
			trim_negative(&numerator);
			r = modulo(numerator, denominator, base);
			prepend_negative(&r);
		}
		else if (denominator[0] == '-' && numerator[0] != '-')
		{
			trim_negative(&denominator);
			r = modulo(numerator, denominator, base);
		}
	}
	return (r);
}

