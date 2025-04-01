/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:24:14 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/03/30 14:22:15 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/talk.h"

void setup_signal(void (*handler)(int, siginfo_t *, void *))
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        write(2, "Error in sigaction\n", 19);
        exit(EXIT_FAILURE);
    }
}
