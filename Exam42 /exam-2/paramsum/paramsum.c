




#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n )
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	
}

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		write(1, "0\n", 2);
		return 0;
	}

	ft_putnbr(argc - 1);
	write(1, "\n", 1);


	return 0;
}