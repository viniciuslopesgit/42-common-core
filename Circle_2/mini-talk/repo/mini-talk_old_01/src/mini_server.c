/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:29:03 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/03/30 14:20:44 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/talk.h"
#include "../includes/ft_printf.h"

static volatile sig_atomic_t g_running = 1;

void	signal_handler(int signo, siginfo_t *info, void *context)
{
    static int bit_count = 0;
    static unsigned char char_bit = 0;    

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
	// Manda o "ack" pro client usando o PID que veio no info
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		write(2, "Error! Can't sent ack\n", 22);
		exit(EXIT_FAILURE);
	}
}

void	sigint_handler(int signo)
{
	(void)signo;
	g_running = 0; // encerra o programa de forma limpa
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
