/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:47:22 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/15 20:55:07 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// itoa start
int	get_length(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*handle_zero(char *ptr)
{
	ptr = malloc(2);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		x;
	char	*ptr;
	long	number;

	number = (long )n;
	ptr = 0;
	if (number == 0)
		return (handle_zero(ptr));
	ptr = malloc(sizeof(char) * (get_length(number) + 1));
	if (!ptr)
		return (0);
	x = get_length(number);
	ptr[x] = '\0';
	if (number < 0)
		number = number * -1;
	x--;
	while (number != 0)
	{
		ptr[x] = (number % 10) + 48;
		number = number / 10;
		x--;
	}
	ptr[x] = '-';
	return (ptr);
}
// itoa finish
