/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:36:14 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/22 08:57:20 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_separator(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}

int word_count(char *str)
{
	int i 		= 0;
	int word 	= 0;

	while(str)
	{
		while(str[i] && is_separator(str[i]))
			i++;
		if (str[i] && !is_separator(str[i]))
		{
			word++;
			while(str[i] && !is_separator(str[i]))
				i++;
		}
	}
	return (word);
}

char *malloc_word(char *str, int len)
{
	int i = 0;
	char *word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);

	while(str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	int i = 0;
	int word = 0;
	int start = 0;
	char **result;

	result = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
	if (!result)
		return(NULL);
	
	result[word] = NULL;
	
	while (str[i])
	{
		while (str[i] && is_separator(str[i]))
			i++;
		if (str[i] && !is_separator(str[i]))
		{
			start = i;
			while(str[i] && !is_separator(str[i]))
				i++;
			result[word++] = malloc_world(&str[start], (i - start));
		}
	}
	result = NULL;
	return (result);
}