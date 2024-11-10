/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:54:06 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/31 18:19:53 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_ptr;
	unsigned char		*dest_ptr;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	src_ptr = (const unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	while (n--)
		dest_ptr[n] = src_ptr[n];
	return (dest);
}
/*
int main(int argc, char **argv)
{
	char src[] = "Hello, World!";
	char dest[20];
	size_t size = 16;

	ft_memmove(dest, src, sizeof(src));
	printf("ft_memmove(%s): %s\n", src, dest);
	rerturn (0);
}
*/