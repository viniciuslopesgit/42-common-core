/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:55:49 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:29:19 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	vc;

	vc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == vc)
			return ((char *)&s[i]);
		i++;
	}
	if (vc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(int argc, char **argv)
{
	// ft_strchr: Busca a primeira ocorrencia de um char em uma str.
	if (argv < 2)
		return (1);
	printf("ft_strchr(%s): %s\n", argv[1], ft_strchr(argv[1], argv[1][0]));
	return (0);
}
*/