/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:15:04 by viniciuslop       #+#    #+#             */
/*   Updated: 2024/12/03 00:42:12 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_hex(int num, int upper) {
    if (num >= 16) {
        ft_putnbr_hex(num / 16, upper); 
    }
    char hex_chars_lower[] = "0123456789abcdef";
    char hex_chars_upper[] = "0123456789ABCDEF";
    if (upper)
    {
        write(1, &hex_chars_upper[num % 16], 1);
    }
    else
    {
        write(1, &hex_chars_lower[num % 16], 1);
    }
}