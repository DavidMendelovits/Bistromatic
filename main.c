/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:17:08 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/12 22:00:32 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int     main(int argc, char **argv)
{
    int     num_len;

    if (argc != 3)
        return (0);
    num_len = ft_atoi(argv[2]);
    begin_parse(argv[1], num_len);
    return (0);
}
