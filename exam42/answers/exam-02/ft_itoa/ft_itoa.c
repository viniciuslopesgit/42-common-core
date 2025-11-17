/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:30:26 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/06/10 02:44:57 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_len(int n)
{
	int len = 0;
	
	if (n == 0)
		return 1;
	
	if(n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = (n / 10);
		len++;
	}
	return len;
}


char	*ft_itoa(int nbr)
{

	int len = ft_len(nbr);
	
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;
	result[len] = '\0';

	int i = 0;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
		i = 1;
	}
	else
		i = 0;

	while(len > i)
	{
		--len;
		result[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	
	return (result);
}


// int main(int argc, char **argv)
// {

// 	char *str = ft_itoa(atoi(argv[1]));

// 	int i = 0;
// 	int len = ft_len(atoi(argv[1]));
	
// 	while(i <= len)
// 	{
// 		printf("%c", str[i]);
// 		i++;
// 	}
// 	free(str);
// 	return 0;
// }