/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:34:16 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 14:21:48 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void			pad_string_zero(char **str, int pad, char zero)
{
	char			*tmp;
	int				sp;
	int				tp;

	sp = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + pad + 1));
	tp = 0;
	while (pad)
	{
		tmp[tp] = zero;
		pad -= 1;
		tp += 1;
	}
	while ((*str)[sp])
	{
		tmp[tp] = (*str)[sp];
		tp += 1;
		sp += 1;
	}
	tmp[tp] = '\0';
	*str = tmp;
}

int				get_num(char n, char *base)
{
	int			p;

	p = 0;
	while (base[p])
	{
		if (base[p] == n)
		{
			return (p);
		}
		p += 1;
	}
	return (p);
}

char			operate(char a_, char b_, char *base, int *carry)
{
	int			a;
	int			b;
	int			c;
	char		c_;
	int			base_len;

	a = get_num(a_, base);
	b = get_num(b_, base);
	c = a + b + *carry;
	base_len = ft_strlen(base);
	if (c >= base_len)
	{
		*carry = c / base_len;
		c %= base_len;
	}
	else
	{
		*carry = 0;
	}
	c_ = base[c];
	return (c_);
}

char			*add(char *o1, char *o2, char *base)
{
	char		*sum;
	int			p;
	int			sp;
	int			carry;

	p = ft_strlen(o1) - 1;
	sum = (char *)ft_memalloc(sizeof(char) * (p + 3));
	sp = 0;
	carry = 0;
	while (p >= 0)
	{
		sum[sp] = operate(o1[p], o2[p], base, &carry);
		sp += 1;
		p -= 1;
	}
	sum[sp] = base[carry];
	ft_strrev(sum);
	return (sum);
}

char			*addition(char *o1, char *o2, char *base)
{
	int				p1;
	int				p2;
	char			*sum;

	if (o1[0] == '-' || o2[0] == '-')
	{
		return (redirect_addition(o1, o2, base));
	}
	p1 = ft_strlen(o1) - 1;
	p2 = ft_strlen(o2) - 1;
	if (p1 < p2)
	{
		pad_string_zero(&o1, p2 - p1, base[0]);
	}
	else if (p2 < p1)
	{
		pad_string_zero(&o2, p1 - p2, base[0]);
	}
	sum = add(o1, o2, base);
	if (sum[0] == base[0])
		trim_zeros(&sum, base);
	return (sum);
}
