/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:02:57 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/17 14:18:09 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

char			*division_by_int(char *numerator, int denominator, char *base)
{
	char			quotient[1024];
	int				tmp;
	char			*tmp1;
	char			*tmp2;
	int				p;
	int				qp;
	int				R;

	p = 0;
	qp = 0;
	tmp = 0;
	while (numerator[p])
	{
		if (p > 0)
			tmp *= ft_strlen(base);
		tmp += ft_atoi_base(numerator[p], base);
		if (tmp > denominator)
		{
			quotient[qp] = base[tmp / denominator];
			tmp %= denominator;
		}
	}
}

int				main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", division_by_int(argv[1], ft_atoi(argv[2]), "0123456789"));
	}
	return (0);
}
