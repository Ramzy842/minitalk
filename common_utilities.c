/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:54:50 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/13 22:30:02 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert_to_decimal(const char	*str)
{
	int	len;
	int	decimal;
	int	x;

	len = ft_strlen(str);
	decimal = 0;
	x = 0;
	while (x < len)
	{
		if (str[x] == '1')
			decimal = decimal + powerize(2, len - x - 1);
		x++;
	}
	return ((char)decimal);
}

char	*convert_to_binary(char c)
{
	static char		byte[9];
	int				decimal;
	int				x;

	byte[8] = '\0';
	decimal = (int)c;
	x = 7;
	while (x >= 0)
	{
		if (powerize(2, x) <= decimal)
		{
			byte[7 - x] = '1';
			decimal = decimal - powerize(2, x);
		}
		else
			byte[7 - x] = '0';
		x--;
	}
	return (byte);
}

// ft_strlen start
int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
// ft_strlen end

// powerize  start
int	powerize(int base, unsigned int power)
{
	long long				result;
	unsigned int			x;

	if (power == 0)
		return (1);
	if (base == 0)
		return (0);
	result = 1;
	x = 0;
	while (x < power)
	{
		result = result * base;
		x++;
	}
	return (result);
}
// powerize end

// putstr start
void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}
// putstr finish