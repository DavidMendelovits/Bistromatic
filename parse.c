/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:05:27 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/13 21:41:04 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include <string.h> //take out later

int     begin_parse(char *base, int expr_size)
{
	char	*expr;

	printf("begin parse\n");
    expr = read_expression(expr_size);
	display_nbr_origin(base);
	parse_expr(expr, base);
	printf("begin_parse -> parse_expr");
    return (1);
}

char    *read_expression(int expr_size)
{
	printf("read_expr\n");
    int     ret;
    char    buf[expr_size + 1];
    char	*_buf;

    ret = read(0, buf, expr_size);
    buf[expr_size] = '\0';
    printf("ret: %i\n", ret);
    if (ret == -1)
    {
        printf("error, no file read");
        return (NULL);
    }
	_buf = strdup(buf);
    printf("buffer: %s\n", buf);
    return (_buf);
} 

/* strdup in place while I fix my ft_strdup */

void	display_nbr_origin(char *base)
{
	printf("NBR_ORIGIN\n");
	while (*base)
	{
		printf(GRN "[");
		printf("%c", *base++);
		printf("] " RESET);
	}
	printf("\n");
}


