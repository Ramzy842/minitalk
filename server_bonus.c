/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:50:23 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/17 16:55:44 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_server_tracker;

int	check_null_terminator(const char *str)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (x < 8)
	{
		if (str[x] == '0')
			count++;
		x++;
	}
	if (count == 8)
		return (1);
	else
		return (0);
}

void	received_sig(char c, pid_t	process_pid)
{
	static char		bin[9];
	char			decimal_character;

	if (g_server_tracker < 8)
	{
		if (c == '1')
			bin[g_server_tracker] = '1';
		else if (c == '0')
			bin[g_server_tracker] = '0';
		g_server_tracker++;
	}
	if (g_server_tracker == 8)
	{
		bin[8] = '\0';
		decimal_character = (char) convert_to_decimal(bin);
		write(1, &decimal_character, 1);
		if (check_null_terminator(bin) == 1)
			kill(process_pid, SIGUSR1);
		g_server_tracker = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *p)
{
	static pid_t	process_pid;

	(void)p;
	if (process_pid != info->si_pid)
	{
		process_pid = info->si_pid;
		g_server_tracker = 0;
	}
	if (signum == SIGUSR1)
		received_sig('1', info->si_pid);
	if (signum == SIGUSR2)
		received_sig('0', info->si_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					pid;

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
	ft_putstr(ft_itoa(pid));
	ft_putstr("\n");
	while (1)
		;
	return (0);
}
