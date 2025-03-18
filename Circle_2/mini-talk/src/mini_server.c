////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                                 Minitalk - SERVER                                  ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////

#include "../includes/talk.h"
#include "../includes/ft_printf.h"

void signal_handler(int signo, siginfo_t *info, void *context) // DEBUG
{
    ft_printf("Sinal recebido: %d\n", signo);
    ft_printf("Sinal recebido: %d\n", info);
    ft_printf("Sinal recebido: %d\n", context);
}

int main(void)
{
    pid_t mini_server;
    
    mini_server = getpid();
    setup_signal(signal_handler);
    ft_printf("PID do processo: %i\n", mini_server);
    ft_printf("Envie sinais usando SIGUSR1 e SIGUSR2 para este processo:\n");
    while (1) pause();
    return EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                                 SETUP-SIGNAL-TEST                                  ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////


// void signal_handler(int signo, siginfo_t *info, void *context)
// {
//     printf("Sinal recebido: %i\n", signo);
// }

// int main()
// {
//     setup_signal(signal_handler);
//     printf("PID do processo: %i\n", getpid());
//     printf("Envie sinais SIGUR1 ou SIGUSR2 para este processo.\n");
//     while (1)
//         pause();
//     return 0;
// }