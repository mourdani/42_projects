/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 06:58:35 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/12 08:00:18 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_end_sig(char **msg, int pid)
{
	if (kill(pid, SIGUSR1) == -1)
	{
		if (*msg)
			free(*msg);
		ft_putstr_fd("An error occured.\n", 2);
		exit(1);
	}
}

void	print_free(char **msg)
{
	ft_putstr(*msg);
	free(*msg);
	*msg = NULL;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static char	c = 0xFF;
	static char	*msg = 0;
	static int	bits = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (!c)
			print_free(&msg);
		else
			msg = ft_straddc(msg, c);
		bits = 0;
		c = 0xFF;
	}
	send_end_sig(&msg, pid);
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr("server PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
