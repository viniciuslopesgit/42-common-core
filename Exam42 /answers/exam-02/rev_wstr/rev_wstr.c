


#include <unistd.h>
#include <stdio.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void ft_pustr(char *str, int start, int end)
{
	while(start < end)
		write(1, &str[start++], 1);
}

int main (int argc, char **argv)
{

	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}

	char *str = argv[1];
	int i = 0;
	int len = 0;

	while(str[len])
		len++;

	int start = 0;
	int end = len;
	while(len >= 0)
	{
		if (is_space(str[len]) || len == 0)
		{
			if (len == 0)
				start = 0;
			else
				start = len + 1;
			ft_pustr(str, start, end);
			if (len > 0 || is_space(str[len]))
				write(1, " ", 1);
			end = len;
		}
		--len;
	}
	write(1, "\n", 1);

	return 0;
}