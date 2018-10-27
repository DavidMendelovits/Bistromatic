/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 19:03:59 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 17:07:02 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			get_dif(char a_, char b_, char *base, int *borrow)
{
	int			a;
	int			b;
	int			c;
	char		c_;
	int			base_len;

	a = get_num(a_, base);
	b = get_num(b_, base);
	c = a - b - *borrow;
	base_len = ft_strlen(base);
	if (c < 0)
	{
		*borrow = 1;
		c += base_len;
	}
	else
	{
		*borrow = 0;
	}
	c_ = base[c];
	return (c_);
}

void			swap_strings(char **a, char **b)
{
	char		*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char			*subtract(char *o1, char *o2, char *base)
{
	char		*dif;
	int			p;
	int			dp;
	int			borrow;
	int			sign;

	p = ft_strlen(o1) - 1;
	dif = (char *)ft_memalloc(sizeof(char) * (p + 3));
	dp = 0;
	borrow = 0;
	if (ft_strcmp(o1, o2) < 0)
	{
		swap_strings(&o1, &o2);
		sign = -1;
	}
	while (p >= 0)
	{
		dif[dp] = get_dif(o1[p], o2[p], base, &borrow);
		dp += 1;
		p -= 1;
	}
	if (sign == -1)
		dif[dp++] = '-';
	(dp) ? ft_strrev(dif) : 0;
	return (dif);
}

char			*trim_zero_neg(char *num, char *base)
{
	char		*new;
	char		*tmp;
	int			p;

	p = 1;
	while (num[p] == base[0])
	{
		p += 1;
	}
	tmp = ft_strdup_range(num, p, ft_strlen(num) - 1);
	new = ft_strjoin("-", tmp);
	free(tmp);
	return (new);
}

char			*subtraction(char *o1, char *o2, char *base)
{
	int			p1;
	int			p2;
	char		*difference;

	if (o1[0] == '-' || o2[0] == '-')
	{
		return (redirect_subtraction(o1, o2, base));
	}
	p1 = ft_strlen(o1) - 1;
	p2 = ft_strlen(o2) - 1;
	if (p1 < p2)
	{
		pad_string_zero(&o1, p2 - p1, base[0]);
	}
	if (p2 < p1)
	{
		pad_string_zero(&o2, p1 - p2, base[0]);
	}
	difference = subtract(o1, o2, base);
	if (difference[0] == '-')
		return (trim_zero_neg(difference, base));
	else if (difference[0] == base[0])
		trim_zeros(&difference, base);
	return (difference);
}
