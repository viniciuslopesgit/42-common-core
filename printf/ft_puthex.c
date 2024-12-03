/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:40:19 by viniciuslop       #+#    #+#             */
/*   Updated: 2024/12/03 00:42:09 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_puthex(unsigned int n)
{
    char *hex;

    hex = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16);
    ft_putchar(hex[n % 16]);
    return (1);
}

int ft_putpointer(unsigned long ptr)
{
    return(ft_puthex(ptr));
}