/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:02:57 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 13:39:17 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_div.h"
#include <assert.h>

char			get_dif(char _a, char _b, char *base, int *borrow)
{
//	FUNC();
	int			a;
	int			b;
	int			c;
	char		_c;
	int			base_len;

	a = get_num(_a, base);
	b = get_num(_b, base);
	c = a - b - *borrow;
//	printf("%d - %d - (%d)\n", a, b, *borrow);
//	printf("dif (c): %d\n", c);
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
//	printf("borrow: %d\n", *borrow);
//	printf("c: %d\n", c);
//	printf("_c = base[%d] (%c)\n", c, base[c]);
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
 //   FUNC();
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
  //  	printf("%s\n%s\n", o1, o2);
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
//	printf("difference: %s\n", dif);
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
//	free(tmp);
	return (new);
}

char			*redirect_subtraction(char *o1, char *o2, char *base)
{
	char			*dif;

	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		dif = subtraction(o2, o1, base);
	}
	else if (o1[0] == '-' && o2[0] != '-')
	{
		trim_negative(&o1);
		dif = addition(o1, o2, base);
		prepend_negative(&dif);
	}
	else if (o1[0] != '=' && o2[0] == '-')
	{
		trim_negative(&o2);
		dif = addition(o1, o2, base);
	}
	return (dif);
}

char			*subtraction(char *o1, char *o2, char *base)
{
//	FUNC();
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
 //   printf("%s\n%s\n", o1, o2);
	difference = subtract(o1, o2, base);
 //   printf("difference: %s\n", difference);
	if (difference[0] == '-')
		return (trim_zero_neg(difference, base));
	else if (difference[0] == base[0])
		trim_zeros(&difference, base);
	return (difference);
}

void            pad_string_zero(char **str, int pad, char zero)
{
//    printf("->%s\n", __func__);
    char            *tmp;
    int             sp;
    int             tp;

    sp = 0;
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + pad + 1));
    tp = 0;
    while (pad)
    {
        tmp[tp] = zero;
        pad -= 1;
        tp += 1;
    }
    while ((*str)[sp])
    {
        tmp[tp] = (*str)[sp];
        tp += 1;
        sp += 1;
    }
    tmp[tp] = '\0';
    *str = tmp;
}

int             get_num(char n, char *base)
{
 //   printf("->%s\n", __func__);
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

void	           trim_zeros(char **num, char *base)
{
//	FUNC();
    char            *new;
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
//	free(*num);
	*num = new;
}

char            operate(char _a, char _b, char *base, int *carry)
{
//    printf("->%s\n", __func__);
    int         a;
    int         b;
    int         c;
    char        _c;
    int         base_len;

    a = get_num(_a, base);
    b = get_num(_b, base);
    c = a + b + *carry;
//    printf("%d + %d + (%d)\n", a, b, *carry);
 //   printf("sum (c): %d\n", c);
    base_len = ft_strlen(base);
    if (c >= base_len)
    {
        *carry = c / base_len;
//		printf("carry now set to %d\n", *carry);
        c %= base_len;
    }
    else
    {

        *carry = 0;
//		printf("carry now set to %d\n", *carry);
    }
//    printf("c mod base: %d\n", c);
//    printf("carry: %d\n", *carry);
 //   printf("_c = base[%d] (%c)\n", c, base[c]);
    _c = base[c];

//    printf("return _c (%c)\n", _c);
    return (_c);
}

char            *add(char *o1, char *o2, char *base)
{
//    printf("->%s\n", __func__);
    char        *sum;
    int         p;
    int         sp;
    int         carry;

    p = ft_strlen(o1) - 1;
    sum = (char *)ft_memalloc(sizeof(char) * (p + 3));
    sp = 0;
	carry = 0;
    while (p >= 0)
    {
		sum[sp] = operate(o1[p], o2[p], base, &carry);
//        printf("sum[%d] = %c\n", sp, sum[sp]);
//		printf("sum = %s\n", sum);
		sp += 1;
		p -= 1;
    }
    sum[sp] = base[carry];
	ft_strrev(sum);
//	printf("sum = %s\n", sum);
    return (sum);
}

void			trim_negative(char **o)
{
	char			*new;

	new = ft_strdup_range(*o, 1, ft_strlen(*o));
//	free(*o);
	*o = new;
}

void			prepend_negative(char **o)
{
	char			*new;

	new = ft_strjoin("-", *o);
//	free(*o);
	*o = new;
}

char			*redirect_addition(char *o1, char *o2, char *base)
{
	char			*sum;

	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		sum = addition(o1, o2, base);
		prepend_negative(&sum);
	}
	else if (o1[0] == '-' && o2[0] != '-')
	{
		trim_negative(&o1);
		sum = subtraction(o2, o1, base);
	}
	else if (o1[0] != '-' && o2[0] == '-')
	{
		trim_negative(&o2);
		sum = subtraction(o1, o2, base);
	}
	return (sum);
}

char            *addition(char *o1, char *o2, char *base)
{
//    printf("->%s\n", __func__);
    int             p1;
    int             p2;
    char            *sum;

	if (o1[0] == '-' || o2[0] == '-')
	{
		return (redirect_addition(o1, o2, base));
	}
    p1 = ft_strlen(o1) - 1;
    p2 = ft_strlen(o2) - 1;
    if (p1 < p2)
    {
        pad_string_zero(&o1, p2 - p1, base[0]);
    }
    else if (p2 < p1)
    {
        pad_string_zero(&o2, p1 - p2, base[0]);
    }
//    printf("%s\n%s\n", o1, o2);
    sum = add(o1, o2, base);
//    printf("sum: %s\n", sum);
	if (sum[0] == base[0])
    	trim_zeros(&sum, base);
//    printf("sum: %s\n", sum);
	return (sum);
}

void                init_o(t_mult *o, char *_o, char *base)
{
  //  FUNC();
    int             i;

    o->len = ft_strlen(_o);
    o->p = 0;
    o->num = (int *)ft_memalloc(sizeof(int) * (o->len));
    i = o->len - 1;
    while (i >= 0 && _o[i] != '-')
    {
        o->num[o->p] = get_num(_o[i], base);
        i -= 1;
        o->p += 1;
    }
    o->p = 0;
 //   for (i = 0; i < o->len; i++)
 //       printf("%d ", o->num[i]);
//    printf("\n");
}

void                iterate_multiply(int **prod, t_mult *o1, t_mult *o2)
{
//    FUNC();
    o1->p = 0;
    while (o1->p < o1->len)
    {
        (*prod)[o1->p + o2->p] += o1->num[o1->p] * o2->num[o2->p];
        o1->p += 1;
    }
   // for (int i = 0; i < (o1->len + o2->len); i += 1)
//        printf("%d ", (*prod)[i]);
//    printf("\n");
}

int                *multiply(t_mult *o1, t_mult *o2, char *base)
{
//    FUNC();
    int             *product;
    int             radix;
    int             tmp;
    int             i;

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

char                *read_r_product(int *_prod, int len, char *base)
{
 //   FUNC();
    char            *prod;
    int             i;
    int             p;

    prod = (char *)ft_memalloc(sizeof(char) * (len + 1));
    i = 0;
    p = len - 1;
    while (_prod[p] == 0 && p >= 0)
        p -= 1;
    while (p >= 0)
    {
        prod[i] = base[_prod[p]];
        p -= 1;
        i += 1;
    }
    return (prod);
}

char				*redirect_multiplication(char *o1, char *o2, char *base)
{
	char				*product;

	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		product = multiplication(o1, o2, base);
	}
	else if (o1[0] == '-' || o2[0] == '-')
	{
		if (o1[0] == '-')
			trim_negative(&o1);
		else if (o2[0] == '-')
			trim_negative(&o2);
		product = multiplication(o1, o2, base);
		prepend_negative(&product);
	}
	return (product);
}

char                *multiplication(char *_o1, char *_o2, char *base)
{
//    FUNC();
    t_mult          o1;
    t_mult          o2;
    int             *r_product;
    char            *product;

	if (is_zero(_o1, base) || is_zero(_o2, base))
	{
//		printf("1\n");
		return (ft_strdup_range(base, 0, 0));
	}
	else if (_o1[0] == '-' || _o2[0] == '-')
	{
//		printf("2\n");
		return (redirect_multiplication(_o1, _o2, base));
	}

	init_o(&o1, _o1, base);
    init_o(&o2, _o2, base);
//	printf("%s * %s\n", _o1, _o2);
    r_product = multiply(&o1, &o2, base);
    product = read_r_product(r_product, o1.len + o2.len, base);
//	printf("product = %s\n", product);
    return (product);
}

char			*division_by_int(char *numerator, int denominator, char *base)
{
//	FUNC();
	char			*quotient;
	int				tmp;
	int				p;
	int				qp;

//	printf("n = %s\nd = %d\n", numerator, denominator);
	p = 0;
	qp = 0;
	tmp = 0;
	quotient = ft_memalloc(sizeof(char) * (ft_strlen(numerator) + 1));
	while (numerator[p])
	{
//		printf("numerator[%d] = %c\n", p, numerator[p]);
		if (p > 0)
			tmp *= ft_strlen(base);
		tmp += get_num(numerator[p++], base);
//		printf("tmp = %d\ndenom = %d\n", tmp, denominator);
		if (tmp >= denominator)
		{
			quotient[qp] = base[tmp / denominator];
			qp += 1;
//			printf("quotient[%d] = base[%d / %d] (%c)\n", qp - 1, tmp, denominator, base[tmp/denominator]);
			tmp %= denominator;
		}
		else
		{
			quotient[qp++] = base[0];
//			printf("quotient[%d] = base[0] (%c)\n", qp - 1, base[0]);
		}
	}
	if (quotient[0] == base[0] && ft_strcmp(quotient, "0"))
		trim_zeros(&quotient, base);
	return (quotient);
}

char			*abs_value(char *num)
{
//	FUNC();
	char			*new;

	if (num[0] == '-')
	{
		new = ft_strdup(num);
		trim_negative(&new);
		return (new);
	}
	return (num);
}

int				compare(char *o1, char *o2, char *base)
{
//	FUNC();
	int			p;

//	printf("%s ? %s\n", o1, o2);
	p = 0;
	if (ft_strlen(o1) > ft_strlen(o2) && o1[0] != '-')
	{
		return (1);
	}
	else if (ft_strlen(o1) < ft_strlen(o2) && o2[0] != '-')
	{
		return (-1);
	}
	else if (!ft_strcmp(o1, o2))
	{
		return (0);
	}
	else
	{
		while (o1[p] && o2[p])
		{
			if (get_num(o1[p], base) > get_num(o2[p], base))
			{
				return (1);
			}
			else if (get_num(o1[p], base) < get_num(o2[p], base))
			{
				return (-1);
			}
			p += 1;
		}
	}
	return (0);
}

int				is_zero(char *num, char *base)
{
//	FUNC();
	int				i;

	i = 0;
	while (num[i])
	{
		if (num[i] != base[0])
		{
	//		printf("%c isn't zero\n", num[i]);
			return (0);
		}
		i += 1;
	}
//	printf("is zero!\n");
	return (1);
}

char			*do_division(char *num, char *denom, char *base)
{
	int				M;
	char			*Q;
	char			*Qn;
	char			*R;
	char			*N;
	char			*tmp;
	char			*tmp2;

	M = ft_strlen(denom) - 1;
	N = ft_strdup_range(num, 0, ft_strlen(num) - M - 1);
//	printf("N (%s) / A (%c)\n", N, denom[0]);
	Q = division(N, ft_strdup_range(denom, 0, 0), base);
//	printf("Q = %s\n",Q);
//	free(N);
	R = addition(denom, "1", base);
//	printf("R = %s\n", R);
	int i = 0;
	while (compare(abs_value(R), denom, base) >= 0)
	{
//		printf("doing...\nR = N - (Q * D)\n");
		tmp = multiplication(Q, denom, base);
//		printf("--------------------tmp = %s\n", tmp);
		R = subtraction(num, tmp, base);
//		printf("-----------------R (new) = %s\n", R);
		if (is_zero(R, base))
			break ;
//		free(tmp);	
//	free(N);
//		printf("doing...\nQn = Q + R/A\n");
		if (ft_strlen(R) >= M + 1)
			N = ft_strdup_range(R, 0 , ft_strlen(R) - M - 1);
		else
		{
			N = ft_strdup_range(base, 0, 0);
		}
//		printf(" Q(%s) + R(%s) / A(%c)\n", Q, R, denom[0]);
		tmp = division(N, ft_strdup_range(denom, 0, 0), base);
	//	free(N);
//		printf("---------------tmp (R/A) = %s\n", tmp);
		Qn = addition(Q, tmp, base);
//		printf("-----------------Qn = %s\n", Qn);
//		free(tmp);
//		printf("------------Q (%s) + Qn (%s)\n", Q, Qn);
		tmp = addition(Q, Qn, base);
//		free(Q);
//		free(Qn);
		Q = division(tmp, ft_strdup_range(base, 2, 2), base);
//		printf("-------------new Q = %s\n", Q);
//		free(tmp);
		i++;
	}
	tmp = multiplication(Q, denom, base);
	R = subtraction(num, tmp, base);
	free(tmp);
	printf("%d loops\n", i);
	printf("end loop\n");
	printf("Q = %s\n", Q);
	printf("R = %s\n",  R);
	if (R[0] == '-')
	{
		tmp = subtraction(Q, ft_strdup_range(base, 1, 1), base);
		Q = ft_strdup(tmp);
		free(tmp);
		tmp = addition(R, denom, base);
		R = ft_strdup(tmp);
		free(tmp);
	}
//	if (!compare(R, denom, base))
//	{
//		tmp = subtraction(R, denom, base);
//		R = ft_strdup(tmp);
//		free(tmp);
//		tmp = addition(Q, ft_strdup_range(base, 1, 1), base);
//		Q = ft_strdup(tmp);
//		free(tmp);
//	}
	printf("checking...\n");
	char	*check = addition(multiplication(Q, denom, base), R, base);
	printf("%s -\n%s -\n", check, num);
	if (!ft_strcmp(num, check))
		printf("matched!\n");
	printf("Q = %s\n", Q);
	printf("R = %s\n", R);
	return (Q);
}

char			*redirect_division(char *o1, char *o2, char *base)
{
	char				*quotient;

	if (o1[0] == '-' && o2[0] == '-')
	{
		trim_negative(&o1);
		trim_negative(&o2);
		quotient = division(o1, o2, base);
	}
	else if (o1[0] == '-' || o2[0] == '-')
	{
		if (o1[0] == '-')
		{
			trim_negative(&o1);
		}
		else if (o2[0] == '-')
		{
			trim_negative(&o2);
		}
		quotient = division(o1, o2, base);
		prepend_negative(&quotient);
	}
	return (quotient);
}

char			*division(char *numerator, char *denominator, char *base)
{
//	FUNC();

	if (numerator[0] == '-' || denominator[0] == '-')
	{
		return (redirect_division(numerator, denominator, base));
	}
	if (is_zero(numerator, base))
		return ("0");
	else if (is_zero(denominator, base))
		return ("undefined!\n");
	if (ft_strlen(numerator) == ft_strlen(denominator))
	{
		if (compare(numerator, denominator, base) < 0)
			return ("0");
		else if (!ft_strcmp(numerator, denominator))
			return ("1");
	}
	if (ft_strlen(numerator) < ft_strlen(denominator))
	{
		return ("0");
	}
	else if (ft_strlen(denominator) == 1)
	{
		return (division_by_int(numerator, get_num(denominator[0], base), base));
	}
	else if (*numerator && *denominator)
	{
		if (denominator[0] == base[1] && ft_strlen(denominator) == 1)
			return (numerator);
		printf("no!\n");
		return (do_division(numerator, denominator, base));
	}
	else
		return (NULL);
//	return (quotient);
}


int				main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("\n%s\n", addition(ft_strdup(argv[1]), ft_strdup(argv[3]), "0123456789"));
		else if (argv[2][0] == '-')
			printf("\n%s\n", subtraction(ft_strdup(argv[1]), ft_strdup(argv[3]), "0123456789"));
		else if (argv[2][0] == 'p')
			printf("\n%s\n", multiplication(ft_strdup(argv[1]), ft_strdup(argv[3]), "0123456789"));
		else if (argv[2][0] == '/')
			printf("\n%s\n", division(ft_strdup(argv[1]), ft_strdup(argv[3]), "0123456789"));
	
	}
	return (0);
}
