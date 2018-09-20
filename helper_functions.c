/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:15:14 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/19 19:15:24 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char			*ft_chardup(char _c)
{
	char			*c;

	printf("\nfunction -> ft_chardup\n");
	c = malloc(sizeof(*c) * 2);
	c[0] = _c;
	c[1] = '\0';
	return (c);
}
