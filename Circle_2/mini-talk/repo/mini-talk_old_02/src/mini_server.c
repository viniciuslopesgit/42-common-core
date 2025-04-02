/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:29:03 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/02 01:35:15 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/talk.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static int				bit_count;
	static unsigned char	char_bit;

	(void)context;
	if (signo == SIGUSR2)
		char_bit |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (char_bit == '\0')
			write(1, "\n", 1);
		else
			write(1, &char_bit, 1);
		bit_count = 0;
		char_bit = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		write(2, "Error! Can't sent ack\n", 22);
		exit(EXIT_FAILURE);
	}
}

void	sigint_handler(int signo)
{
	(void)signo;
	g_running = 0;
	ft_printf("\nServidor encerrado.\n");
	exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_printf("Server PID: %i\n\n", getpid());
	setup_signal(signal_handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
