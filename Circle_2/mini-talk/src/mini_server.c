////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                                 Minitalk - SERVER                                  ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////

#include "../includes/talk.h"
#include "../includes/ft_printf.h"

#include "../includes/talk.h"
#include "../includes/ft_printf.h"

void signal_handler(int signo, siginfo_t *info, void *context)
{
    static int bit_count = 0;              // Variável para contar os bits
    static unsigned char char_bit = 0;     // Variável para armazenar o caractere reconstruído

    (void)info;  // Ignorando as variáveis não utilizadas
    (void)context;

    //ft_printf("Sinal recebido: %d de PID: %d\n", signo, info->si_pid);

    // Verifica o sinal recebido
    if (signo == SIGUSR2)
        char_bit |= (1 << (7 - bit_count));  // Se for SIGUSR2, marca o bit como 1

    // Aumenta a contagem de bits
    bit_count++;

    // Quando 8 bits forem recebidos, o caractere está completo
    if (bit_count == 8)
    {
        if (char_bit == '\0')  // Se for o caractere nulo ('\0'), termina a mensagem
            write(1, "\n", 1);  // Fim da mensagem
        else
            write(1, &char_bit, 1);  // Caso contrário, escreve o caractere reconstruído

        // Reseta as variáveis para o próximo caractere
        bit_count = 0;
        char_bit = 0;
    }
}

int main(void)
{
    ft_printf("Server PID: %i\n\n", getpid());  // Exibe o PID do servidor
    setup_signal(signal_handler);  // Configura o handler de sinais
    //ft_printf("Envie sinais usando SIGUSR1 e SIGUSR2 para este processo:\n");
    // Espera indefinidamente por sinais
    while (1)
        pause();

    return EXIT_SUCCESS;
}
