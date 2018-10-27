/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:35:35 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 16:36:15 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void				init_o(t_mult *o, char *o_, char *base)
{
	int				i;

	o->len = ft_strlen(o_);
	o->p = 0;
	o->num = (int *)ft_memalloc(sizeof(int) * (o->len));
	i = o->len - 1;
	while (i >= 0 && o_[i] != '-')
	{
		o->num[o->p] = get_num(o_[i], base);
		i -= 1;
		o->p += 1;
	}
	o->p = 0;
}

void				iterate_multiply(int **prod, t_mult *o1, t_mult *o2)
{
	o1->p = 0;
	while (o1->p < o1->len)
	{
		(*prod)[o1->p + o2->p] += o1->num[o1->p] * o2->num[o2->p];
		o1->p += 1;
	}
}

int					*multiply(t_mult *o1, t_mult *o2, char *base)
{
	int				*product;
	int				radix;
	int				tmp;
	int				i;

	product = (int *)ft_memalloc(sizeof(int) * (o1->len + o2->len + 1));
	radix = ft_strlen(base);
	while (o2->p < o2->len)
	{
		iterate_multiply(&product, o1, o2);
		o2->p += 1;
	}
	i = 0;
	while (i < (o1->len + o2->len))
	{
		tmp = product[i] / radix;
		product[i] %= radix;
		product[i + 1] += tmp;
		i += 1;
	}
	return (product);
}

char				*read_r_product(int *prod_, int len, char *base)
{
	char			*prod;
	int				i;
	int				p;

	prod = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = 0;
	p = len - 1;
	while (prod_[p] == 0 && p >= 0)
		p -= 1;
	while (p >= 0)
	{
		prod[i] = base[prod_[p]];
		p -= 1;
		i += 1;
	}
	return (prod);
}

char				*multiplication(char *o1_, char *o2_, char *base)
{
	t_mult			o1;
	t_mult			o2;
	int				*r_product;
	char			*product;

	if (is_zero(o1_, base) || is_zero(o2_, base))
	{
		return (ft_strdup_range(base, 0, 0));
	}
	else if (o1_[0] == '-' || o2_[0] == '-')
	{
		return (redirect_multiplication(o1_, o2_, base));
	}
	init_o(&o1, o1_, base);
	init_o(&o2, o2_, base);
	r_product = multiply(&o1, &o2, base);
	product = read_r_product(r_product, o1.len + o2.len, base);
	return (product);
}
