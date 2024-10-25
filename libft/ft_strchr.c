/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:55:49 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/25 21:19:47 by vilopes          ###   ########.fr       */
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
