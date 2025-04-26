/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:55:23 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/22 00:11:14 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while(n % 2 == 0)
		n = n / 2;
	if (n == 1)
		return (1);
	else
		return (0);
}

// int main(int argc, char **argv)
// {
// 	printf("Resultado: %d\n", is_power_of_2(atoi(argv[1])));
// 	return (0);
// }