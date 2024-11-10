/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:54:41 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/24 20:09:29 by vilopes          ###   ########.fr       */
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
	if (argc < 2)
		return (1);
		//ft_bzero
	ft_bzero(buffer, sizeof(buffer));
	printf("ft_bzero(%c): %s Buffer zerado!\n", argv[1][0], buffer);
}
*/