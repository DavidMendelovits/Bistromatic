/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_pt2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:19:58 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 18:25:00 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			*abs_value(char *num)
{
	char			*new;

	if (num[0] == '-')
	{
		new = ft_strdup(num);
		trim_negative(&new);
		return (new);
	}
	return (num);
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

char			*avg(char *a, char *b, char *base)
{
	char			*tmp;
	char			*average;

	tmp = addition(a, b, base);
	average = division(tmp, ft_strdup_range(base, 2, 2), base);
	free(tmp);
	return (average);
}

void			increment(char **o1, char *o2, char *base)
{
	char			*new;

	new = addition(*o1, o2, base);
	free(*o1);
	*o1 = new;
}

int				compare(char *o1, char *o2, char *base)
{
	int			p;

	p = 0;
	if (ft_strlen(o1) > ft_strlen(o2) && o1[0] != '-')
		return (1);
	else if (ft_strlen(o1) < ft_strlen(o2) && o2[0] != '-')
		return (-1);
	else if (!ft_strcmp(o1, o2))
		return (0);
	else
	{
		while (o1[p] && o2[p])
		{
			if (get_num(o1[p], base) > get_num(o2[p], base))
				return (1);
			else if (get_num(o1[p], base) < get_num(o2[p], base))
				return (-1);
			p += 1;
		}
	}
	return (0);
}
