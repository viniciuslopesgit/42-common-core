



#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n )
{
		if (n == -2147483648)
			write(1, "-2147483648", 11);

		if (n < 0)
		{
			n = n * -1;
			write(1, "-", 1);
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
}

int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return(result * sign);
}

int main(int argc, char **argv)
{

	if (argc != 2 || ft_atoi(argv[1]) < 0)
	{
		write(1, "0\n", 2);
		return 0;
	}

	int n = ft_atoi(argv[1]);
	int i = 0;
	int sum = 1;

	while(i++ <= n)
	{
		if (i % 2 != 0)
		{
			sum = sum + i;
		}
	}
	ft_putnbr(sum);
	write(1, "\n", 1);

	return 0;
}