

#include <unistd.h>
#include <stdio.h>

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
		int j = 0;
		while(str[i])
		{
			if ((str[i] == ' ') && (str[i + 1] >= 33 && str[i + 1] <= 126))
				j = i + 1;
			i++;
		}
		while(str[j] >= 33 && str[j] <= 126)
		{
			write(1, &str[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);



	return 0;
}