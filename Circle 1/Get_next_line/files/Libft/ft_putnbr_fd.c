/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:45:26 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:27:03 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nm, int fd)
{
	unsigned int	nbr;

	if (nm < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nm * -1);
	}
	else
		nbr = (unsigned int)nm;
	if (nbr > 9)
		ft_putnbr_fd((nbr / 10), fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
/*
int	main(int argc, char **argv)
{
	// ft_putnbr_fd: Escreve os numeros em um arquivo ou fluxo.
	int	number;

	number = ft_atoi(argv[1]);
	ft_putnbr_fd(number, 1);
	return (0);
}
*/