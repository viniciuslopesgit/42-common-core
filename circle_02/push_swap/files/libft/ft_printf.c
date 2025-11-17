/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:06:42 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/25 01:27:15 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_printf_check(char s, va_list *args, long int *len, long int *i)
{
	if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_putpointer(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_putunsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_puthex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_puthex(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

long int	ft_printf(const char *string, ...)
{
	va_list		args;
	long int	i;
	long int	len;

	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_check(string[i], &args, &len, &i);
		}
		else
		{
			ft_putchar_len((char)string[i], &len);
		}
		i++;
	}
	va_end(args);
	return (len);
}
