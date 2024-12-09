/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:49:36 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:36:41 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	if (*little == 0)
		return ((char *)big);
	len = ft_strlen(little);
	if (len == 0)
		return (0);
	while (*big && n >= len)
	{
		if (ft_strncmp(big, little, len) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}
/*
int main(int argc, char **argv)
{
	// ft_strnstr: Busca uma substr em uma str principal.
	if (argc == 4)
	{
		printf("ft_strnstr: %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
		printf("strnstr: %s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
*/