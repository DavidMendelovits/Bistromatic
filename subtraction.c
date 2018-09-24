/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 19:03:59 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/23 13:37:41 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
//#include "libft/libft.h"
#define WOW() printf("->%s\n", __func__);

char			get_dif(char _a, char _b, char *base, int *borrow)
{
	WOW();
	int			a;
	int			b;
	int			c;
	char		_c;
	int			base_len;

	a = get_num(_a, base);
	b = get_num(_b, base);
	c = a - b - *borrow;
	printf("%d - %d - (%d)\n", a, b, *borrow);
	printf("dif (c): %d\n", c);
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
	b_printf("borrow: %d\n", *borrow);
	b_printf("c: %d\n", c);
	b_printf("_c = base[%d] (%c)\n", c, base[c]);
	_c = base[c];
	return (_c);
	
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
    WOW();
	char		*dif;
	int         p;
    int         dp;
    int         borrow;
	int			sign;

    p = ft_strlen(o1) - 1;
    dif = (char *)ft_memalloc(sizeof(char) * (p + 3));
    dp = 0;
    borrow = 0;
	if (ft_strcmp(o1, o2) < 0)
	{
		swap_strings(&o1, &o2);
		sign = -1;
    	b_printf("%s\n%s\n", o1, o2);
	}
    while (p >= 0)
    {
        dif[dp] = get_dif(o1[p], o2[p], base, &borrow);
		dp += 1;
		p -= 1;
    }
	if (sign == -1)
	{
		dif[dp++] = '-';
	}
	if (dp)
		ft_strrev(dif);
	b_printf("difference: %s\n", dif);
	return (dif);
}

char			*subtraction(char *o1, char *o2, char *base)
{
	WOW();
	int			p1;
	int			p2;
	char		*difference;

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
    b_printf("%s\n%s\n", o1, o2);
	difference = subtract(o1, o2, base);
    printf("difference: %s\n", difference);
	return (difference);
}
