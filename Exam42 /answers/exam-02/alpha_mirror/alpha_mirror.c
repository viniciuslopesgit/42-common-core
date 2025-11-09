

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;

		while(str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = (97 - str[i]) + 122;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 65 - str[i] + 90;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	return 0;
}