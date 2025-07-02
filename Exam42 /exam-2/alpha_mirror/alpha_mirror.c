



#include <unistd.h>

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		char *str = argv[1];

		int i = 0;
		while(str[i])
		{
			if (str[i] && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = (90 - str[i] + 65);
			else if (str[i] && str[i] >= 'a' && str[i] <= 'z')
				str[i] = (122 - str[i] + 97);
			
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);


	return 0;
}