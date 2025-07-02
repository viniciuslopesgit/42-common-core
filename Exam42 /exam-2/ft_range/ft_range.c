


#include <stdlib.h>


int     *ft_range(int start, int end)
{
	int len = end - start;

	if (len < 0)
		len = (len * -1) + 1;
	else
		len = (len * 1) + 1;

	int *result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return NULL;

	int i = 0;
	while(i < len)
	{
		if (start < end)
			result[i] = start++;
		else
			result[i] = start--;

		i++;
	}


	return result;
}