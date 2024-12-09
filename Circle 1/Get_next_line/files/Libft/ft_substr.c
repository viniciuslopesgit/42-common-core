/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:18 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:55:01 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	str_len;
	size_t	actual_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	actual_len = str_len - start;
	if (actual_len > len)
		actual_len = len;
	mem = (char *)malloc((actual_len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s + start, actual_len + 1);
	return (mem);
}
/*
int main(int argc, char **argv)
{
	// ft_substr: extrai um substr de uma string dada, comecando
	// pelo index de "len"
	if (argc == 4)
	{
		printf("ft: %s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
		printf("ori: %s\n", substr(argv[1], atoi(argv[2]), atoi(argv[3])));
	}
	return (0);
}
*/