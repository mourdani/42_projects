/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 06:58:48 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/14 00:03:37 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	send_null(int pid, char **str)
{
	static int	i;

	if (!i)
		i = 0;
	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			free(str);
			return (1);
		}
		return (0);
	}
	return (1);
}

void	send_sig(int sig, int pid, char **msg)
{
	if (sig == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			if (*msg)
				free(*msg);
		}
	}
	if (sig == 2)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			if (*msg)
				free(*msg);
		}
	}
}

int	send_bit(int pid, char *str)
{
	static char	*msg = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (pid)
		s_pid = pid;
	if (str)
		msg = ft_strdup(str);
	if (!msg)
		return (0);
	if (msg[++bits / 8])
	{
		if (msg[bits / 8] & (0x80 >> (bits % 8)))
			send_sig(1, s_pid, &msg);
		else
			send_sig(2, s_pid, &msg);
		return (0);
	}
	if (!send_null(s_pid, &msg))
		return (0);
	free(msg);
	return (1);
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		if (send_bit(0, 0))
		{
			ft_putstr("Message sent!.\n");
			exit(0);
		}
	}
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("An error occured.\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("USAGE : ./client [server PID] [array to send]\n", 2);
		exit(0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_putstr("wrong PID\n");
		exit(0);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
