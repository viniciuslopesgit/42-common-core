


#include <stdio.h>
#include <stdlib.h>


int is_prime(int n)
{
	return (n % 2 != 0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = atoi(argv[1]);

		if (n < 0)
		{
			printf("\n");
			return 0;
		}
		if (n == 1)
		{
			printf("1\n");
			return 0;
		}

		int i = 2;
		while(n >= 2)
		{
			if (n % i == 0)
			{
				n = n / i;
				printf("%d", i);
				if (n >= 2)
					printf("*");
				i = 2;
			}
			i++;
		}
		
	}
	printf("\n");

	return 0;
}