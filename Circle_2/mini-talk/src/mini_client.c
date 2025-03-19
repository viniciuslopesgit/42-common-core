////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                                 Minitalk - CLIENT                                  ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////

#include "../includes/talk.h"
#include "../includes/ft_printf.h"

void send_message(int pid, char *message);
int	ft_atoi(const char *str);

int main(int argc, char **argv)
{
    int     pid;

    if (argc != 3)
    {
        ft_printf("Parâmetro inválido: %s <PID> <mensagem>\n", argv[0]); 
        return EXIT_FAILURE;
    }
    pid = ft_atoi(argv[1]);
    send_message(pid, argv[2]);
    return (0);
}

void send_message(int pid, char *message)
{
    int     i;
    int     bit;

    bit = 0;
    for(i = 0; message[i] != '\0'; i++)
    {
        for(bit = 0; bit < 8; bit++)
        {
            if (message[i] & (1 << (7 - bit)))
               kill(pid, SIGUSR2); // Envia '1';
            else
                kill(pid, SIGUSR1); // Envia '0';
            usleep(10);
        }
    }
    for (bit = 0; bit < 0; bit++)
    {
        kill(pid, SIGUSR1);
        usleep(10);
    }
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
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