/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:10:21 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/05 20:18:46 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	size_t	len;
	size_t	i;

	len = ft_strlen(s) + 1;
	mem = (char *)malloc(len * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = s[i];
		i++;
	}
	return (mem);
}
/*
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("Original string: %s\n", argv[1]);
		printf("Duplicated string: %s\n", ft_strdup(argv[1]));
	}
	return (0);
}
*/