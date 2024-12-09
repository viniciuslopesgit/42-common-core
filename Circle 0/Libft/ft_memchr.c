/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:05:07 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:21:55 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
int main(int argc, char **argv)
{
	//ft_memchr: Busca um valor especifico dentro de um area de memoria
	char src[] = "Hello, World!";
	printf("ft_memchr(%s): %p\n", src, ft_memchr(src, 'W', 13));
	return (0);
}
*/