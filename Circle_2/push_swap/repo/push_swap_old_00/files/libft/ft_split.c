/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:30:56 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 22:50:18 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

#include <stdlib.h>
#include <stdio.h>

// static void	ft_freeup(char **strs, int i)
// {
// 	while (i >= 0)
// 	{
// 		free(strs[i]);
// 		i--;
// 	}
// 	free(strs);
// }

static int	ft_wordcount(const char *str, char c)
{
	int	i = 0;
	int	word = 0;

	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char *ft_strndup(const char *src, int n)
{
	char *dest = (char *)malloc(n + 1);
	if (!dest)
		return (NULL);
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
	dest[n] = '\0';
	return (dest);
}

char **ft_split(const char *str, char c)
{
	char **result;
	int words = ft_wordcount(str, c);
	int i = 0, j = 0, start = 0;

	if (!str || !(result = (char **)malloc((words + 1) * sizeof(char *))))
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] && str[i] != c)
				i++;
			result[j++] = ft_strndup(&str[start], i - start);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
