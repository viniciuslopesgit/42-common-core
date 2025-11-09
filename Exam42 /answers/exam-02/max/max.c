



int		max(int* tab, unsigned int len)
{
	if (!tab)
		return 0;
		
	int i = 0;
	int max = 0;

	while(tab[i])
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}