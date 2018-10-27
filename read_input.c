/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:41:26 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/21 16:44:54 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int					is_valid_char(char *base, char c)
{
	if (is_op(c) || is_nbr(c, base) || c == '(' || c == ')')
	{
		return (1);
	}
	return (0);
}

char				*read_input(char *base, int input_size)
{
	char				*input;
	char				*buffer;
	int					bp;

	buffer = ft_memalloc(sizeof(char) * (input_size + 1));
	input = NULL;
	bp = 0;
	while (read(0, &buffer[bp], 1))
	{
		if (!is_valid_char(base, buffer[bp]))
			break ;
		bp += 1;
		if (bp >= input_size)
			break ;
	}
	if (bp == input_size)
	{
		input = ft_strdup(buffer);
		printf("input = %s\n", input);
	}
	return (input);
}
