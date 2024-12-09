/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:35:09 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/09 21:06:43 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(long int n, long int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_putnbr(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
}

void	ft_putpointer(size_t ptr, long int *len)
{
	char		str[25];
	long int	i;
	char		*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (ptr == 0)
	{
		ft_putchar_len('0', len);
	}
	while (ptr != 0)
	{
		str[i] = base_char[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_len(str[i], len);
	}
}

void	ft_puthex(unsigned int x, long int *len, char c)
{
	char		str[25];
	char		*base_char;
	long int	i;

	i = 0;
	if (c == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_putunsigned_int(unsigned int n, long int *len)
{
	if (n >= 10)
		ft_putunsigned_int(n / 10, len);
	ft_putchar_len(n % 10 + '0', len);
}
