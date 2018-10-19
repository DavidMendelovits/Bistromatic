/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:28:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/18 18:42:39 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "bistromatic.h"
#include "libft/libft.h"
#define FUNC() printf("=>%s\n", __func__)

int				is_positive(char *num)
{
	FUNC();
	if (num[0] != '-')
	{
		return (1);
	}
	return (0);
}

int				is_zero(char *num, char *base)
{
	int				i;

	i = 0;
	while (num[i])
	{
		if (num[i] != base[0])
		{
			return (0);
		}
		i += 1;
	}
	return (1);
}

char            *trim_zeros(char *num, char *base)
{
    FUNC();
    char            *new;
    int             i;
    int             j;

    num = ft_strrev(num);
    i = 0;
    while (num[i] != base[0])
    {
        i += 1;
    }
    new = (char *)ft_memalloc(sizeof(char) * (i + 1));
    j = 0;
    i -= 1;
    while (i >= 0)
    {
        new[j] = num[i];
        i -= 1;
        j += 1;
    }
    return (new);
}


char			*division_by_int(char *numerator, int denominator, char *base)
{
	char			quotient[1024];
	int				qp;
	int				idx;
	int				tmp;
	int				nlen;

	ft_memset(quotient, '\0', 1024);
	idx = 0;
	tmp = numerator[idx] - base[0];
	printf("tmp = %d\n", tmp);
	while (tmp < denominator)
	{
		tmp = tmp * 10 + (numerator[++idx] - base[0]);
		denominator /= tmp;
		printf("denominator = %d\n", denominator);
		printf("tmp = %d\n", tmp);
	}
	nlen = ft_strlen(numerator)
	qp = 0;
	while (idx < nlen)
	{
		quotient[qp] = (tmp / denominator) + base[0];
		tmp = tmp % denominator * 10 + numerator[++idx];
		qp += 1;
	}
	if (!nlen)
		return ("0");
	return (quotient);
}

char			*trim_denominator(int M, char *denominator, char *base)
{
	char			*new;
	char			*tmp;
	char			*zero;

	tmp = ft_strdup_range(denominator, 0, 0);
	zero = ft_memalloc(sizeof(char) * (M + 1));
	ft_memset(zero, base[0], M);
	new = ft_strjoin(tmp, zero);
	free(zero);
	free(tmp);
	return (new);
}

char			*do_division(char *num, char *denom, char *base)
{
	int				M;
//	char			*A;
	char			*Q;
	char			*Qn;
	char			*R;
	char			*N;

	M = ft_strlen(denom) - 1;
//	A = trim_denominator(M, denom, base);
	N = ft_strdup_range(num, 0, ft_strlen(num) - M);
	printf("N (%s) / A (%c)\n", N, denom[0]);
	Q = division_by_int(N, denom[0], base);
	int			p = ft_strlen(denom) - 1;
	char		*one_plus = ft_strdup(denom);
	one_plus[p] = one_plus[p] - base[
	R = 
}

char			*division(char *numerator, char *denominator, char *base)
{
	FUNC();
	if (ft_strlen(numerator) < ft_strlen(denominator))
	{
		return ("0");
	}
	else if (ft_strlen(numerator) > 10 && ft_strlen(denominator) == 1)
	{
		return (division_by_int(numerator, ft_atoi(denominator), base));
	}
	else if (*numerator && *denominator)
	{
		return (do_division(numerator, denominator, base));
	}
	
	return (quotient);
}

