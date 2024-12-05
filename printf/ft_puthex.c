/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:40:19 by viniciuslop       #+#    #+#             */
/*   Updated: 2024/12/05 01:35:17 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned long n, int is_upper)
{
    char *hex;
    int count = 0;

    hex = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16)
        count += ft_puthex(n / 16, is_upper);
    ft_putchar(hex[n % 16]);
    count++;
    return (count);
}

int ft_putpointer(unsigned long ptr)
{
    if (!ptr)
        return (ft_putstr("(nil)")); 
    return (ft_putstr("0x") + ft_puthex(ptr, 0));
}

int ft_putnbr_hex(unsigned long n, int is_upper)
{
    return (ft_puthex(n, is_upper));
}
