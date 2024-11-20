/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:43:38 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/20 21:27:15 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int ft_putnumber(int num) {
    char *buffer;
    int len;

    buffer = ft_itoa(num);
    if (!buffer)
        return (-1);

    len = ft_strlen(buffer); // Agora compatível com o protótipo corrigido
    write(1, buffer, len);
    free(buffer);
    return (len);
}