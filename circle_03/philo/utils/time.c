#include "../philosophers.h"

// Estas funções são usadas em toda a simulação (logs, tempo de comer/dormir, detectar mortes)
long    get_time_ms(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void    ms_sleep(long ms)
{
    long    start;
    
    start = get_time_ms();
    while (get_time_ms() - start < ms)
        usleep(100); // dorme pouco para não sobrecarregar a CPU
}