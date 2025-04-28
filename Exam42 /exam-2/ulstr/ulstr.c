


#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char *str = argv[1];

		while(str[i])
		{
			if (str[i] && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (str[i] && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
