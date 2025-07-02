






#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	int len = 0;

	while(src[len])
		len++;

	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;

	while(src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';

	return result;
}


// int main(int argc, char **argv)
// {

// 	char *result = ft_strdup(argv[1]);

// 	printf("%s\n", result);

// 	return 0;
// }
