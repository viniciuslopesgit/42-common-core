/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:54:41 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:17:16 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int main(int argc, char **argv)
{
	// ft_bzero: Preenche um bloco de memoria com valores nulos.
	if (argc < 2)
		return (1);
		//ft_bzero
	ft_bzero(buffer, sizeof(buffer));
	printf("ft_bzero(%c): %s Buffer zerado!\n", argv[1][0], buffer);
}
*/