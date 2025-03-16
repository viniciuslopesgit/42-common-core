#include "../includes/talk.h"
#include "../includes/ft_printf.h"

int main(void)
{
    pid_t mini_server;
    
    mini_server = getpid();

    ft_printf("Father: %d\n", mini_server);
    return EXIT_SUCCESS;
}