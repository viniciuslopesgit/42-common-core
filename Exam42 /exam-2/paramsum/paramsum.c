/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:24:15 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 16:27:27 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n)
{
	unsigned int nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
		
}

int main (int argc, char **argv)
{

	(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}