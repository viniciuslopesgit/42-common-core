/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:07:31 by viniciuslop       #+#    #+#             */
/*   Updated: 2024/12/02 23:07:43 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_putunsigned(unsigned int n)
{
	int print_char;

	print_char = 0;
	if (n >= 10)
		print_char += ft_putunsigned(n / 10);
	ft_putchar((n % 10) + '0');
	print_char++;
	return (print_char);
}
