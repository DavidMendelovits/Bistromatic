/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   approach_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiuza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:28:33 by lfiuza            #+#    #+#             */
/*   Updated: 2018/07/13 01:27:29 by lfiuza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "approach_2.h"

t_digits	*ft_lstnew(int digit)
{
	t_digits *new;

	new = (t_digits *)malloc(sizeof(t_digits));
	if (!new)
		return (NULL);
	new->digit = digit;
	new->prev = NULL;
	return (new);
}

void	ft_lstpushback(t_digits **last_digit, int digit)
{
	t_digits	*number;

	number = *last_digit;
	if (!number)
		*last_digit = ft_lstnew(digit);
	else
	{
		while (number->prev)
			number = number->prev;
		number->prev = ft_lstnew(digit);
	}
}

t_digits	*subtract(t_digits **num1, t_digits **num2)
{
	t_digits	*result;
	t_digits	*numb1;
	t_digits	*numb2;
	int			diff;
	int			carryover;

	numb1 = *num1;
	numb2 = *num2;
	carryover = 0;
	while (numb1 || numb2)
	{
		diff = 0;
		if (numb1)
		{
			if (carryover)
			{
				diff--;
				carryover = 0;
			}
			diff += numb1->digit;
			numb1 = numb1->prev;
		}
		if (numb2)
		{
			if (diff < numb2->digit)
			{
				diff += BASE;
				carryover = 1;
			}
			diff -= numb2->digit;
			numb2 = numb2->prev;
		}
		ft_lstpushback(&result, diff);
	}
	return (result);
}

t_digits	*add(t_digits **num1, t_digits **num2)
{
	t_digits	*result;
	t_digits	*numb1;
	t_digits	*numb2;
	int			digit;
	int			carryover;
	int			sum;

	numb1 = *num1;
	numb2 = *num2;
	result = NULL;
	carryover = 0;
	while (numb1 || numb2)
	{
		sum = 0;
		if (numb1)
		{
			sum += numb1->digit;
			numb1 = numb1->prev;
		}
		if (numb2)
		{
			sum += numb2->digit;
			numb2 = numb2->prev;
		}
		sum += carryover;
		digit = sum % BASE;
		ft_lstpushback(&result, digit);
		carryover = sum / BASE;
	}
	return (result);
}

int		main(void)
{
	t_digits	*number1;
	t_digits	*number2;
	t_digits	*addition_result;
	t_digits	*subtraction_result;
	
	number1 = NULL;
	number2 = NULL;
	ft_lstpushback(&number1, 6);
	ft_lstpushback(&number1, 3);
	ft_lstpushback(&number1, 5);
	
	ft_lstpushback(&number2, 8);
	ft_lstpushback(&number2, 6);
	addition_result = add(&number1, &number2);
	while (addition_result)
	{
		printf("%i\n", addition_result->digit);
		addition_result = addition_result->prev;
	}
	printf("---\n");
	subtraction_result = subtract(&number1, &number2);
	while (subtraction_result)
	{
		printf("%i\n", subtraction_result->digit);
		subtraction_result = subtraction_result->prev;
	}
	return (0);
}
