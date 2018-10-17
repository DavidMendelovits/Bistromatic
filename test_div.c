/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:02:57 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/17 15:24:17 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

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
	int				R;

	p = 0;
	qp = 0;
	tmp = 0;
	R = 0;
	quotient = ft_memalloc(sizeof(char) * (ft_strlen(numerator) + 1));
	while (numerator[p])
	{
		if (p > 0)
			tmp *= ft_strlen(base);
		tmp += ft_atoi_base(ft_strdup_range(&numerator[p], 0, 0), base);
		if (tmp >= denominator)
		{
			quotient[qp] = base[tmp / denominator];
			qp += 1;
			tmp %= denominator;
		}
		else
			quotient[qp++] = base[0];
		p += 1;
	}
	if (tmp)
		R = tmp;
	if (quotient[0] == base[0])
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
