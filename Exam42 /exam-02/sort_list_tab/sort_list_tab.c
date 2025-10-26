


void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1]) // ele só precisa verificar atéo penúltimo número, pois depois disso ele nao tem mais com o que comparar a frente (ex:  {..2, 5} -> só vai até o 2) ou seja: (SIZE - 1)
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}


#include <stdio.h>
int main()
{
	int nbr[] = {1, 5, 2, 0, 3};
	int len = sizeof(nbr) / sizeof(nbr[0]);
	printf("%lu\n", sizeof(nbr[0]));

	sort_int_tab(nbr, len);

	int i = 0;
	while(i < len)
	{
		printf("%d, ", nbr[i]);
		i++;
	}
}