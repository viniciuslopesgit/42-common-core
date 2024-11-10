/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:31:49 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:23:40 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
/*
int main (int argc, char **argv)
{
	// ft_memcpy: Copia uma quantidade de bytes de um bloco de
	// memoria para outro
	char src[] = "Hello, World!";
	char dest[20];
	size_t size = 16;
	ft_memcpy(dest, src, sizeof(src));
	printf("ft_memcpy(%s): %s\n", src, dest);
	return (0);
}
*/