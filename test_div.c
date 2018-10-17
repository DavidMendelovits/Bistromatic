/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:02:57 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/17 16:01:34 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int             get_num(char n, char *base)
{
    printf("->%s\n", __func__);
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

char            *trim_zeros(char *num, char *base)
{
    char            *new;
	int				p;
	int				np;

	p = 0;
	while (num[p] == base[0])
	{
		p += 1;
	}
	new = ft_strdup_range(num, p, (ft_strlen(num) - 1));
	free(num);
	return (new);
}

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
		if (p > 0)
			tmp *= ft_strlen(base);
		tmp += get_num(numerator[p++], base);
		if (tmp >= denominator)
		{
			quotient[qp++] = base[tmp / denominator];
			tmp %= denominator;
		}
		else
			quotient[qp++] = base[0];
	}
	if (quotient[0] == base[0] && ft_strcmp(quotient, "0"))
		return (trim_zeros(quotient, base));
	return (quotient);
}

int				main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("\n%s\n", division_by_int(argv[1], ft_atoi(argv[2]), "0123456789"));
	}
	return (0);
}
