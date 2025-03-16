#include "../includes/talk.h"
#include "../includes/ft_printf.h"

int main(void)
{
    ft_printf("Client: %d\n", getpid());
    return EXIT_SUCCESS;
}