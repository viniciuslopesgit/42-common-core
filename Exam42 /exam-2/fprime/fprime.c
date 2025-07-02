/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:46:49 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/10 18:08:54 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = atoi(argv[1]);
		int divisor = 2;

		if (n == 1)
		{
			printf("1\n");
			return 0;
		}
		while(n > 1)
		{
			if (n % divisor == 0)
			{
				printf("%d", divisor);
				n = n / divisor;
				if (n > 1)
					printf("*");
			}
			else
				divisor++;	
		}
	}
	printf("\n");

	return 0;
}