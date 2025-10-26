



#include <stdlib.h>
#include <stdio.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int count_word(char *str)
{
	if (!str)
		return 0;
	int words = 0;
	int i = 0;
	while(str[i])
	{
		while(str[i] == ' ')
			i++;
		if (str[i] && !is_space(str[i]))
		{
			words++;
			while(str[i] && !is_space(str[i]))
				i++;
		}
	}
	return words;
	
}

char *malloc_word(char *str, int len)
{

	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;

	int i = 0;
	while(i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return result;
 }

char    **ft_split(char *str)
{

	int i = 0;
	int len = count_word(str);

	int words = 0;
	int start = 0;
	int end = 0;

	char **result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return NULL;

	while(str[i])
	{
		while(str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			start = i;
			while(str[i] && !is_space(str[i]))
				i++;
			end = i ;
			result[words++] = malloc_word(&str[start], end - start);
		}
	}
	result[words] = NULL;
	return result;
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	char *words = argv[1];
// 	char **str = ft_split(words);

// 	int i = 0;
// 	while(str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
	
// 	return 0;
// }