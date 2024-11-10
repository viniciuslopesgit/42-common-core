/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:35:47 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:17:58 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if ((nmemb != 0) && (size > SIZE_MAX / nmemb))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
int main(int argc, char **argv)
{
	// calloc: Aloca memoria, e inicia todos dos bytes com zero.
	if (argc == 3)
	{
		printf("ft_calloc: %s\n", ft_calloc(atoi(argv[1]), atoi(argv[2])));
		printf("calloc: %s\n", calloc(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}
*/