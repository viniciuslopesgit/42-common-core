/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:37:23 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 15:13:12 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n			= atoi(argv[1]);
		int divisor		= 2;

		if (n == 1)
		{
			printf("1\n");
			return (0);
		}
		
		while (n > 1)
		{
			if (n % divisor == 0)
			{
				printf("%d", divisor);
				n = n / divisor;
				printf("*");
			}
			else
				divisor++;
		}
	}
	printf("\n");
	return (0);
}