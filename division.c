/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:28:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 19:28:48 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			*division_by_int(char *numerator, int denominator, char *base)
{
	char			*quotient;
	int				tmp;
	int				p;
	int				qp;

	p = 0;
	qp = 0;
	tmp = 0;
	quotient = ft_memalloc(sizeof(char) * (ft_strlen(numerator) + 1));
	while (numerator[p])
	{
		(p > 0) ? tmp *= ft_strlen(base) : 0;
		tmp += get_num(numerator[p++], base);
		if (tmp >= denominator)
		{
			quotient[qp] = base[tmp / denominator];
			qp += 1;
			tmp %= denominator;
		}
		else
			quotient[qp++] = base[0];
	}
	if (quotient[0] == base[0] && ft_strcmp(quotient, "0"))
		trim_zeros(&quotient, base);
	return (quotient);
}

char			*guess_r(char *num, char *denom, char *quotient, char *base)
{
	char			*tmp;
	char			*remainder;

	tmp = multiplication(quotient, denom, base);
	remainder = subtraction(num, tmp, base);
	free(tmp);
	return (remainder);
}

char			*guess_quotient(char *q, char *r, char *d, char *base)
{
	int				m;
	char			*qn;
	char			*o1;
	char			*o2;

	m = ft_strlen(d) - 1;
	if (ft_strlen(r) > m)
		o1 = ft_strdup_range(r, 0, ft_strlen(r) - m - 1);
	else
		o1 = ft_strdup_range(base, 0, 0);
	o2 = division(o1, ft_strdup_range(d, 0, 0), base);
	qn = addition(q, o2, base);
	free(o1);
	free(o2);
	return (qn);
}

char			*do_division(char *num, char *denom, char *base, int modulo)
{
	int				m;
	char			*q;
	char			*qn;
	char			*r;
	char			*n;

	m = ft_strlen(denom) - 1;
	n = ft_strdup_range(num, 0, ft_strlen(num) - m - 1);
	q = division(n, ft_strdup_range(denom, 0, 0), base);
	r = addition(denom, "1", base);
	while (compare(abs_value(r), denom, base) >= 0)
	{
		r = guess_r(num, denom, q, base);
		qn = guess_quotient(q, r, denom, base);
		q = avg(q, qn, base);
	}
	r = guess_r(num, denom, q, base);
	if (r[0] == '-')
	{
		increment(&q, "-1", base);
		increment(&r, denom, base);
	}
	return ((modulo) ? (r) : (q));
}

char			*division(char *numerator, char *denominator, char *base)
{
	if (numerator[0] == '-' || denominator[0] == '-')
		return (redirect_division(numerator, denominator, base));
	if (is_zero(numerator, base))
		return (ft_strdup_range(base, 0, 0));
	else if (is_zero(denominator, base))
		return (NULL);
	if (ft_strlen(numerator) == ft_strlen(denominator))
	{
		if (compare(numerator, denominator, base) < 0)
			return (ft_strdup_range(base, 0, 0));
		else if (!ft_strcmp(numerator, denominator))
			return (ft_strdup_range(base, 1, 1));
	}
	if (ft_strlen(numerator) < ft_strlen(denominator))
		return (ft_strdup_range(base, 0, 0));
	else if (ft_strlen(denominator) == 1)
		return (division_by_int(numerator, get_num(denominator[0], base), base));
	else if (*numerator && *denominator)
	{
		if (denominator[0] == base[1] && ft_strlen(denominator) == 1)
			return (numerator);
		return (do_division(numerator, denominator, base, 0));
	}
	else
		return (NULL);
}

