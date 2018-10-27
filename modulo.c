/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:52:18 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 21:44:05 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			*modulo(char *numerator, char *denominator, char *base)
{
	if (numerator[0] == '-' || denominator[0] == '-')
		return (redirect_modulo(numerator, denominator, base));
	if (is_zero(numerator, base))
		return (ft_strdup_range(base, 0, 0));
	if (is_zero(denominator, base))
		return (write_error(SYNTAX_ERROR, sizeof(SYNTAX_ERROR)));
	return (do_division(numerator, denominator, base, 1));
}

