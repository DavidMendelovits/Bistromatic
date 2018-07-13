/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiuza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:01:53 by lfiuza            #+#    #+#             */
/*   Updated: 2018/07/12 20:02:15 by lfiuza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_num.h"

// DELETE the following
#include <stdio.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	len = 0;
	while (s1[len])
	{
		s2[len] = s1[len];
		len++;
	}
	return (s2);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	unsigned int	n;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1);
	n += ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * (n + 1));
	if (!fresh)
		return (NULL);
	fresh[n] = '\0';
	n = 0;
	while (*s1)
	{
		fresh[n] = *s1;
		s1++;
		n++;
	}
	while (*s2)
	{
		fresh[n] = *s2;
		s2++;
		n++;
	}
	return (fresh);
}

int		ft_atoi_unsigned(const char *str)
{
	int i;
	int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

size_t		len_skip_zeros(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char		tiny_half_value(int tens, char ones)
{
	int i;

	i = ones - '0';
	i += (tens * 10);
	return ((i / 2) + '0');
}

char		*half_value(char *str)
{
	size_t	i;
	int		tens;
	int		next_tens;

	i = 0;
	tens = 0;
	while (str[i])
	{
		next_tens = ((str[i] - '0') % 2);
		str[i] = tiny_half_value(tens, str[i]);
		tens = next_tens;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		print_parsed(char *str, size_t len)
{
	size_t	count;
	char	*divided_str;

	count = 0;
	divided_str = ft_strdup(str);
	while (len > 9)
	{
		divided_str = half_value(divided_str);
		len = len_skip_zeros(divided_str);
		count++;
	}
	free(divided_str);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./calc number");
		return (1);
	}
	print_parsed(argv[1], ft_strlen(argv[1]));
	return (0);
}

// what I want to do:
// 		- create a function that gets a number that is any-size and add that
// 		a linked list
// 		- create an array of linkedlists/operators?
//
// the beginning of the linked list represents the "last" section of the whole number
// 1 unsigned int = 10 digits
// 2 unsigned int = 20 digits
//
