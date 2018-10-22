/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 15:00:51 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 15:51:10 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define EXP_ERROR "Error -> exponent too large to process"

char				*iterate_power(char *o, int power, char *base)
{
	FUNC();
	int             i;
	char            *power_of;

	i = 1;
	power_of = ft_strdup(o);
	while (i < power)
	{
		o = multiplication(o, power_of, base);
		i += 1;
	}
	return (o);
}

char				*exponent(char *o, char *power_, char *base)
{
	FUNC();
	int				power;
	char			*result;

	if (ft_strlen(power_) > 5)
	{
		write(2, EXP_ERROR, ft_strlen(EXP_ERROR));
		return (NULL);
	}
	power = ft_atoi_base(power_, base);
	if (power == 0)
	{
		return ("1");
	}
	else if (power < 0)
	{
		return (ft_chardup(base[0]));
	}
	else
	{
		result = iterate_power(o, power, base);
	}
	return (result);
}
