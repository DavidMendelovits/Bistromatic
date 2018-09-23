/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 19:03:59 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/22 19:10:52 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#define WOW() printf("->%s\n", __func__);

char			*subtract(char *o1, char *o2, char *base)
{
	char		*dif;
	char		
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
		pad_string_zero(&o1, p2 - p1, base[0]);
	}
    printf("%s\n%s\n", o1, o2, base);
	difference = substract(o1, o2, base);
	return (difference);
}
