/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:26:14 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/27 01:43:36 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int ft_len_nbr(int nbr)
{
	int len 	= 0;
		
	if (nbr == 0)
		return (0);
	if (nbr < 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int len = ft_len_nbr(nbr);
	char *result = (char *)malloc(sizeof(len) + 1);
	if (!result)
		return (NULL);
		
	result[len] = '\0';
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		--len;
		result[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}