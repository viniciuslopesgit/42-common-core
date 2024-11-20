/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:47:51 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/18 22:23:33 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int    ft_putstr(char *str)
{
    size_t len;
    
    len = 0;
    while (str[len])
        len++;
    write(1, str, len);
    return (len);
}