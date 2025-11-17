/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:29:54 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:44:03 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	str = NULL;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		len = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len > i)
			len--;
		str = (char *)malloc(sizeof(char) * (len - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], len - i + 1);
	}
	return (str);
}
/*
int main(int argc, char **argv)
{
	// ft_strtrim: Remove os separadores fornecidos de uma str
	// no seu inicio e final.
	if (argc == 3)
	{
		printf("ft: %s\n", ft_strtrim(argv[1], argv[2]));
	}
	return (0);
}
*/