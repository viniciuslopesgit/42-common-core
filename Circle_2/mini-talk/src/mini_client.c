/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:57:54 by marvin            #+#    #+#             */
/*   Updated: 2025/03/30 14:22:04 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/talk.h"
#include "../includes/ft_printf.h"

static volatile int g_ack_received = 0; // variável global ack


void	send_message(int pid, char *message);
int		ft_atoi(const char *str);
void	ack_handler(int signo, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid parameter: %s <PID> <mensage>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Inválid PID\n");
		return (EXIT_FAILURE);
	}
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}

void	send_message(int pid, char *message)
{
	int	i;
	int	bit;
	int timeout;

	setup_signal(ack_handler); // Configura o handler pro ack
	i = 0;
	while (message[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			g_ack_received = 0; // Reseta a flag antes de mandar
			if (message[i] & (1 << (7 - bit)))
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_printf("Error! Send SIGUSR2\n");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					ft_printf("Error! Send SIGUSR1\n");
					exit(EXIT_FAILURE);
				}
			}
			// Espera o ack do server
			while (!g_ack_received)
				usleep(100); // Pequena espera para não fritar o CPU
			bit++;
		}
		i++;
	}
	// Enviar o \0 com acks
	bit = 0;
	timeout = 10000;
	while (bit < 8)
	{
		g_ack_received = 0;
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error! Send SIGUSR1 (\\0)\n");
			exit(EXIT_FAILURE);
		}
		while (!g_ack_received && timeout > 0)
		{
			usleep(100);
			timeout--;
		}
		if (timeout == 0)
		{	ft_printf("Servidor não responder\n");
			exit(EXIT_FAILURE);
		}
		bit++;
	}
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	ack_handler(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signo == SIGUSR1)
		g_ack_received = 1; // Recebemos o ack, podemos avançar
}