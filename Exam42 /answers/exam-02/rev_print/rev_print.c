



#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];

		int len = 0;
		while(str[len])
			len++;

		while(--len >= 0)
		{
			write(1, &str[len], 1);
		}

	}
	write(1, "\n", 1);

	return 0;
}