/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:49:19 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/17 17:25:49 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	x;

	if (argc != 3)
		return (0);
	x = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	while (argv[2][x] != '\0')
	{
		send_signals(pid, argv[2][x]);
		x++;
	}
	send_signals(pid, '\0');
	return (0);
}
