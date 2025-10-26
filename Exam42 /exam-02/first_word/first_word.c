




#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];

		int i = 0;
		while(str[i])
		{
			while(str[i] && is_space(str[i]))
				i++;

			if (str[i] && !is_space(str[i]))
			{
				while(str[i] && !is_space(str[i]))
				{
					write(1, &str[i], 1);
					i++;
				}
				break;
			}
		}
	}
	write(1, "\n", 1);

	return 0;
}