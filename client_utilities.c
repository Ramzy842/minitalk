/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:28:06 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/13 22:29:41 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char c)
{
	int		x;
	char	*binary_str;

	binary_str = convert_to_binary(c);
	x = 0;
	while (binary_str[x] != '\0')
	{
		if (binary_str[x] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		x++;
	}
}

// atoi start 
static int	convert_to_num(const char *s, int result, int x)
{
	while (s[x] >= '0' && s[x] <= '9')
	{
		result = result * 10 + s[x] - '0';
		x++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	result;
	int	sign;

	x = 0;
	sign = 1;
	result = 0;
	if ((str[0] == '-' && str[1] == '+') || (str[0] == '+' && str[1] == '-'))
		return (0);
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '-')
	{
		sign *= -1;
		x++;
	}
	if (str[x] == '+')
	{
		sign *= 1;
		x++;
	}
	result = convert_to_num(str, result, x);
	return (sign * result);
}
// atoi finish