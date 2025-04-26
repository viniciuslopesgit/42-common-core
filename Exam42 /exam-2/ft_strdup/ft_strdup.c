/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:22:57 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/06 14:57:29 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_len (const char * str);

char *ft_strdup(const char *s)
{
	char *mem;
	int len;
	int i;
	
	len = ft_len(s) + 1;
	mem = (char *)malloc(len * sizeof(char));
	if (!mem)
		return NULL;
	i = 0;
	while (i < len)
	{
		mem[i] = s[i];
		i++;
	}
	return (mem);
	
}

int ft_len(const char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}