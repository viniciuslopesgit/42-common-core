



#include <unistd.h>


int ft_atoi(char *str)
{

	int i = 0;
	int sign = 1;
	int result = 0;

	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

void ft_printhex(int n)
{
	char *hex = "0123456789abcdef";

	if (n >= 16)
		ft_printhex(n / 16);
	write(1, &hex[n % 16], 1);

}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		ft_printhex(n);
	}
	write(1, "\n", 1);


	return 0;
}