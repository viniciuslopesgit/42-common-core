////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                               Minitalk - TALK_UTILS                                ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////

#include "../../includes/talk.h"

// typedef struct {
//     int      si_signo;  /* Número do sinal */
//     int      si_errno;  /* Código de erro associado, se aplicável */
//     int      si_code;   /* Código indicando a origem do sinal */
//     pid_t    si_pid;    /* PID do processo que enviou o sinal (se aplicável) */
//     uid_t    si_uid;    /* UID do usuário que enviou o sinal (se aplicável) */
//     void    *si_addr;   /* Endereço da falha de memória (para SIGSEGV, SIGBUS, etc.) */
//     int      si_status; /* Status do filho (para SIGCHLD) */
//     long     si_band;   /* Band event para sinais de I/O (SIGPOLL) */
// } siginfo_t;

void setup_signal(void (*handler)(int, siginfo_t *, void *)) // func (*handler) : void handler(int signo, siginfo_t *info, void *context)
{
    struct sigaction sa; // Usada para especificar o comportamento do sistema ao receber sinais.
    
    sa.sa_flags = SA_SIGINFO; // O manipulador de sinal deve receber informações extras (siginfo_t * e void *).
    sa.sa_sigaction = handler; // Define handler como a função que será chamada quando SIGUSR1 ou SIGUSR2 forem recebidos.
    // Chama sigaction() para associar SIGUSR1 e SIGUSR2 à estrutura sa, ou seja, para configurar handler como o manipulador desses sinais.
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}