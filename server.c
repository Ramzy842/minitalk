/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:49:15 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/17 16:53:46 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_tracker;

void	received_sig(char c)
{
	static char	bin[9];
	char		decimal_character;

	if (g_tracker < 8)
	{
		if (c == '1')
			bin[g_tracker] = '1';
		else if (c == '0')
			bin[g_tracker] = '0';
		g_tracker++;
	}
	if (g_tracker == 8)
	{
		bin[8] = '\0';
		decimal_character = (char) convert_to_decimal(bin);
		write(1, &decimal_character, 1);
		g_tracker = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *p)
{
	static pid_t	process_pid;

	(void)p;
	if (process_pid != info->si_pid)
	{
		process_pid = info->si_pid;
		g_tracker = 0;
	}
	if (signum == SIGUSR1)
		received_sig('1');
	if (signum == SIGUSR2)
		received_sig('0');
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					pid;
	char				*ptr;

	(void) argv;
	action.sa_sigaction = handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	if (argc != 1)
	{
		write(1, "Error: argument count is more than one!\n", 40);
		return (0);
	}
	pid = getpid();
	ptr = ft_itoa(pid);
	ft_putstr(ptr);
	free(ptr);
	ft_putstr("\n");
	while (1)
		;
	return (0);
}
