/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:54:38 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/05 01:39:42 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char			c;
	char			*letter;
	int				numbers;
	unsigned int	numbers_u;
	int				print_char;

	print_char = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				ft_putchar(c);
				print_char++;
			}
			else if (*format == 's')
			{
				letter = va_arg(args, char *);
				if (!letter)
					letter = "\0";
				print_char += ft_putstr(letter);
			}
			else if (*format == 'd' || *format == 'i')
			{
				numbers = va_arg(args, int);
				print_char += ft_putnumber(numbers);
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				print_char += ft_putpointer((unsigned long)ptr);
			}
			else if (*format == 'u')
			{
				numbers_u = va_arg(args, unsigned int);
				print_char += ft_putunsigned(numbers_u);
			}
			else if (*format == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);
				print_char += ft_putnbr_hex(num, 0);
			}
			else if (*format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				print_char += ft_putnbr_hex(num, 1);
			}
			else
			{
				ft_putchar('%');
				ft_putchar(*format);
				print_char += 2;
			}
		}
		else
		{
			write(1, format, 1);
			print_char++;
		}
		format++;
	}
	va_end(args);
	return (print_char);
}


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
