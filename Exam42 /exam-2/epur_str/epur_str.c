#include <unistd.h>

int	has_next_word(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	*str = argv[1];
		int		i = 0;

		while (str[i])
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				write(1, &str[i], 1);
				i++;
			}
			if (has_next_word(str, i))
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
