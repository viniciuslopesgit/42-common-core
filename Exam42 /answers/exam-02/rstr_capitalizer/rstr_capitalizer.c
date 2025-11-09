
#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		int i;
		int j;

		i = 1;
		j = 0;

		while(i <= (argc - 1))
		{
			j = 0;
			while(argv[i][j])
			{
				if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z') && !(argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
					argv[i][j] = argv[i][j] + 32;
				else if ((argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0') && (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
					argv[i][j] = argv[i][j] - 32;
				write(1, &argv[i][j], 1);
				j++;
			}
				write(1, "\n", 1);

			i++;
		}
	}
	else
		write(1, "\n", 1);


	return 0;
}