/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:05:27 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/12 22:02:10 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int     begin_parse(char *base, int expr_size)
{
//	printf("hello\n");
    read_expression(expr_size);
    return (1);
}

char    *read_expression(int expr_size)
{
    int     ret;
    char    buf[expr_size + 1];
    char	*_buf;

    ret = read(0, buf, expr_size);
	buf[ret] = '\0';
    if (ret == -1)
    {
        printf("error, no file read");
        return (NULL);
    }
	_buf = ft_strdup(buf);
    printf("buffer: %s\n", buf);
    return (_buf);
}  
