/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:11:13 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 20:30:40 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}
/*
int	main(int argc, char **argv)
{
	// strrchr: Recebe uma "*s" e um int "c",
		e retorna o endereco do ultimo valor encontrado de "c" dentro de "*s";
	if (argc == 2)
		printf("ft_strrchr: %s", ft_strrchr(argv[1], 'c'));
	return (0);
}
*/