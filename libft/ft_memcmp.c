/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:59:53 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/31 20:32:42 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int main(int argc, char **argv)
{
	char arr1[] = {0x12, 0x34, 0x56};
	char arr2[] = {0x12, 0x34, 0x57};
	int result = ft_memcmp(arr1, arr2, 3);
	printf("ft_memcmp: %d\n", result); // Deve retornar um valor negativo
	return (0);
}
*/