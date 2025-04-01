/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:21:50 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/03/19 23:23:00 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TALK_H
# define TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

void	send_message(int pid, char *message);
void	signal_handler(int signo, siginfo_t *info, void *context);
void	setup_signal(void (*handler)(int, siginfo_t *, void *));

#endif