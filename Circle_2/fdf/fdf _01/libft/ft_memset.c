/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:22:49 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/17 21:39:27 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(int argc, char **argv)
{
	// Preenche uma area com um valor especifico.
	char buffer[10];
	if (argc < 2)
		return (1);
	ft_memset(buffer, argv[1][0], sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = '\0';
	printf("ft_memset(%c): %s\n", argv[1][0], buffer);
	return (0);
}
*/