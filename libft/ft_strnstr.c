/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:49:36 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/31 21:10:21 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t n)
{
    size_t len;

    if (!*little)
        return ((char *)big);
    len = ft_strlen(little);
    if (len > n)
        return (0);
    while (*big && n >= len)
    {
            if (ft_strncmp(big, little, len) == 0)
                    return ((char *)big);
        big++;
        n--;
    }
    return (NULL);
}