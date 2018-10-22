/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:15:14 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 18:19:47 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			*ft_chardup(char c_)
{
	char			*c;

	printf("\nfunction -> ft_chardup\n");
	c = malloc(sizeof(*c) * 2);
	c[0] = c_;
	c[1] = '\0';
	return (c);
}

void			trim_zeros(char **num, char *base)
{
	char			*new;
	char			*tmp;
	int				p;
	int				len;

	len = ft_strlen(*num);
	p = 0;
	tmp = *num;
	while (tmp[p] == base[0] && p < len - 1)
	{
		p += 1;
	}
	new = ft_strdup_range(*num, p, (ft_strlen(*num) - 1));
	*num = new;
}

void			trim_negative(char **o)
{
	char			*new;

	new = ft_strdup_range(*o, 1, ft_strlen(*o));
	*o = new;
}

void			prepend_negative(char **o)
{
	char			*new;

	new = ft_strjoin("-", *o);
	*o = new;
}

void			*write_error(char *err_msg, size_t size)
{
	write(2, err_msg, size);
	return (NULL);
}
/*
** add frees if you get the chance, stupid
*/
