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
