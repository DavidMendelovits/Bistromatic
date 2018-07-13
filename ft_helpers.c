/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:14:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/12 20:18:16 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		neg;

	neg = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * neg);
}

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (!(duplicate = (char*)ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, size);
	return (memory);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
    while (str[i] != '\0')
		i++;
	return (i);
}
