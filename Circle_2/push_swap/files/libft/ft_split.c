/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:30:56 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 01:08:10 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_freeup(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, const char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(const char *str, char c, int *k)
{
	char	*word;
	int		j;
	int		len;

	while (str[*k] != '\0' && str[*k] == c)
		(*k)++;
	j = *k;
	len = 0;
	while (str[*k] != '\0' && str[*k] != c)
	{
		(*k)++;
		len++;
	}
	if (len == 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strcpy(word, str, c, j);
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount(str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(str, c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs, i - 1);
			return (NULL);
		}
		i++;
	}
	return (strs);
}

/*
int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	// ft_split: Recebe um string e divide ela em outras arrays
	// levando em consideracao o separador fornecido.
	strs = ft_split("Hello, World!", ' ');
	i = 0;
	while (strs[i] != NULL)
	{
		printf("ft_split(%s): %s\n", "Hello, World!", strs[i]);
		i++;
	}
	return (0);
}
*/