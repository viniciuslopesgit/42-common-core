/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:54:38 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/20 21:31:24 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int print_char; // count char
    
    print_char = 0;
    va_start(args, format);
    while(*format)
    {
        if  (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c;
                
                c = (char)va_arg(args, int);
                ft_putchar(c);
                print_char++;
            }
            else if (*format == 's')
            {
                char *letter;

                letter = va_arg(args, char *);
                if (!letter)
                    letter = "\0";
                print_char += ft_putstr(letter);
            }
            else if (*format == 'd' || *format == 'i')
            {
                int numbers;
                
                numbers = va_arg(args, int);
                print_char += ft_putnumber(numbers);
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


int main(void)
{
    // char
    char    str_char;
    char    *str;
    int     num1;
    int     num2;

    str_char = 'c';
    str = "Hello World";
    num1 = 10;
    num2 = -2147483648;
    ft_printf("char: %c\n", str_char);
    ft_printf("str: %s\n", str);
    ft_printf("int: %i\n", num1);
    ft_printf("d: %d\n", num2);
    return (0);
}