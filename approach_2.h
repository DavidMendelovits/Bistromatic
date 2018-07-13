/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   approach_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiuza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:29:16 by lfiuza            #+#    #+#             */
/*   Updated: 2018/07/12 23:24:57 by lfiuza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPROACH_H
# define APPROACH_H

# include <stdlib.h>
# include <stdio.h>

# define BASE 10

typedef struct s_digits
{
	struct s_digits	*prev;
	int				digit;
}				t_digits;

#endif
