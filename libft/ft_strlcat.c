/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:49:57 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:33:53 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	i = 0;
	j = len_dest;
	while (src[i] && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
/*
int main(int argc, char **argv)
{
	// ft_strlcat: Concatena duas str levando em consideracao o len.
	if (argc < 2)
		return (1);
	char src[] = "Hello, World!";
	char dest[20];
	size_t size = 16;

	char dest01[] = "cachorro, ";
	ft_strlcat(dest01, argv[1], size);
	if (size > sizeof(argv[1]))
		printf("ft_strlcat(%s): %s\n", argv[1], dest01);
	else
		printf("ft_strlcat: %zu\n", ft_strlcat(dest01, argv[1], size));
	return (0);
}
*/