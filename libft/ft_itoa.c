/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:19:46 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 08:00:56 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_nbrlen(int n)
{
    int len;

    len = 0;
    if (n <= 0)
    {
        len++;
    }
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char *str;
    int len;
    int sign;

    if (n == 0)
    {
        str = (char *)malloc(2 * sizeof(char));
        if (!str)
            return (NULL);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    len = ft_nbrlen(n);
    sign = 0;
    if (n < 0)
    {
        sign = 1;
        n = n * -1;
    }
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    while (len > 0)
    {
        str[--len] = (n % 10) + '0';
        n = n / 10;
    }
    if (sign == 1)
    {
        str[0] = '-';
    }
    return (str);
}
/*
int main(int argc, char **argv)
{
    if (argc ==2)
    {
        char *str = ft_itoa(ft_atoi(argv[1]));
        printf("%s\n", str);
        free(str);
    }
    return (0);
}
*/