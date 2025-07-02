/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:32:40 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/04 14:12:48 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
		int i = 0;
		int len = abs(end - start) + 1;

		int *result = (int *)malloc(sizeof(int) * len);
		if (!result)
			return(NULL);

		result[len] = '\0';
		while(i < len)
		{
			result[i] = end;
			i++;
			end--;
		}
		return (result);
	
}

