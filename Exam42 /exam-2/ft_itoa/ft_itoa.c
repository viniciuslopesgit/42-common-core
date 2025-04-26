/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:38:53 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/26 23:12:15 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

int ft_len_n(int nbr)
{
	int len 	= 0;
	
	if (nbr <= 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while ( nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int len 	= ft_len_n(nbr);
	char *str	= (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		--len;
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
	
}

// int main (int argc, char **argv)
// {
//      printf("%s\n", ft_itoa(0));             // "0"
//      printf("%s\n", ft_itoa(42));            // "42"
//      printf("%s\n", ft_itoa(-42));           // "-42"
//      printf("%s\n", ft_itoa(2147483647));    // "2147483647"
//      printf("%s\n", ft_itoa(-2147483647));   // "-2147483648"

// 	 return (0);
// }