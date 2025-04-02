/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:06:42 by vilopes           #+#    #+#             */
/*   Updated: 2025/03/16 19:19:41 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

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
/*
int	main(void)
{
	char			str_char;
	char			*str;
	int				num1;
	int				num2;
	unsigned int	num3;

	// char
	str_char = 'c';
	str = "Hello World";
	num1 = 35;
	num2 = -2147483648;
	num3 = 4294967254;
	ft_printf("char: %c\n", str_char);
	ft_printf("str: %s\n", str);
	ft_printf("int: %i\n", num1);
	ft_printf("d: %d\n", num2);
	ft_printf("p: %p\n", &num1);
	ft_printf("u: %u\n", num3);
	ft_printf("x: %x\n", 255);
	ft_printf("X: %X\n", 255);
	ft_printf("p: %p %p", 0, 0);
	return (0);
}
*/
