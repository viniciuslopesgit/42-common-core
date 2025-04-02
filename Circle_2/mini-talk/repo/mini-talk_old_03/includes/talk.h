/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:21:50 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/02 01:29:02 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TALK_H
# define TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"

static volatile sig_atomic_t	g_running = 1;
static volatile int				g_ack_received = 0;

void	send_message(int pid, char *message);
void	signal_handler(int signo, siginfo_t *info, void *context);
void	setup_signal(void (*handler)(int, siginfo_t *, void *));
int		ft_atoi(const char *str);

void	ack_handler(int signo, siginfo_t *info, void *context);
void	send_bit(int pid, int bit);
void	send_char(int pid, char c);
void	send_null(int pid);
void	send_message(int pid, char *message);
#endif
