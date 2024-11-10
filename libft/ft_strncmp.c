/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:24:24 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/31 19:57:34 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		if (ptr1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
int main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("Original string: %s\n", argv[1]);
		printf("String to compare: %s\n", argv[2]);
		printf("Number of characters to compare: %s\n", argv[3]);
		printf("Result: %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
*/