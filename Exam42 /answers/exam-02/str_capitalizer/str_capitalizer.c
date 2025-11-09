



#include <unistd.h>

void str_capitalizer(char *str)
{
	int i = 0;
	int is_first = 1; // indica se é o início de uma palavra

	while(str[i])
	{
		if (is_first && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			is_first = 0;
		}
		else if (!is_first && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		
		// Verifica se é a primeira palavra
	 	if (str[i] == ' ' || str[i] == '\t')
			is_first = 1;
		else
			is_first = 0;
		write(1, &str[i], 1);
		i++;
	}
}


int main (int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return 1;
	}

	int i = 1;
	while(i < argc)
	{
		str_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}

	return 0;
}