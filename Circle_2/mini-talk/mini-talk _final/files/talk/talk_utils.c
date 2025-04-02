/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:24:14 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/02 01:34:57 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/talk.h"

void	setup_signal(void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset (&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error in sigaction\n", 19);
		exit(EXIT_FAILURE);
	}
}

void	send_bit(int pid, int bit)
{
	g_ack_received = 0;
	if (bit)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error! Sending SIGUSR2\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error! Sending SIGUSR1\n");
			exit(EXIT_FAILURE);
		}
	}
	while (!g_ack_received)
		usleep(100);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, c & (1 << (7 - bit)));
		bit++;
	}
}

void	send_null(int pid)
{
	int	bit;
	int	timeout;

	bit = 0;
	timeout = 10000;
	while (bit < 8)
	{
		g_ack_received = 0;
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error! Sending SIGUSR1 (\\0)\n");
			exit(EXIT_FAILURE);
		}
		while (!g_ack_received && timeout > 0)
		{
			usleep(100);
			timeout--;
		}
		if (timeout == 0)
		{
			ft_printf("Server not answer\n");
			exit(EXIT_FAILURE);
		}
		bit++;
	}
}

void	ack_handler(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signo == SIGUSR1)
		g_ack_received = 1;
}
