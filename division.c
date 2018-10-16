/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:28:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/04 14:17:37 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

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
        j += 1
    }
    return (new);
}

char			*division(char *_o1, char *_o2, char *base)
{
	FUNC();
	char			*quotient;
	char			*tmp;

	tmp = _o1;
	quotient = ft_strdup_range(base, 0, 0);
	while (is_positive(tmp) && !(is_zero(tmp, base)))
	{
		tmp = subtraction(tmp, _o2, base);
		if (!is_positive(tmp))
			break ;
		quotient = addition(quotient, ft_strdup_range(base, 1, 1), base);
		printf("quotient: %s\n", quotient);
	}
    if (quotient[0] == base[0])
    {
        quotient = trim_zeros(quotient, base);
    }
	return (quotient);

}

