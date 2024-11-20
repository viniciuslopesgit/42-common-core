/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:49:08 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/18 20:50:15 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    va_list args; // declara uma variavel para gerenciar os argumentos
    va_start(args, count); // iniciliza args para comecar no primeiro argumento
    int result_sum;
    int i;
    
    result_sum = 0;
    i = 0;
    while (i < count)
    {
        result_sum += va_arg(args, int);
        //printf("COUNT: %i\n", result_sum);
        i++;
    }
    va_end(args);
    return (result_sum);
    
}

int main()
{
    printf("Sum result: %d\n", sum(4, 12, 3, 4, 5));
    return (0);
}