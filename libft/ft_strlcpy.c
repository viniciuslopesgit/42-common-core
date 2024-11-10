/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:17:55 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:34:18 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int main(int argc, char **argv)
{
	// ft_strlcpy: Copia uma string levando em consideracao o tamanho da len.
	char src[] = "Hello, World!";
	char dest[20];
	size_t size = 16;

	ft_strlcpy(dest, src, size);
	if (!size)
		printf("ft_strlcpy: %zu\n", ft_strlcpy(dest, src, size));
	else
		printf("ft_strlcpy(%s): %s\n", src, dest);
	return (0);
}
*/