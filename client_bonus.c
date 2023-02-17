/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:50:20 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/17 17:26:45 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *p)
{	
	(void)info;
	(void)p;
	if (signum == SIGUSR1)
		ft_putstr("Message Received!");
}

int	main(int argc, char **argv)
{
	int					pid;
	int					x;
	struct sigaction	action;

	(void) argv;
	action.sa_sigaction = handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
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
