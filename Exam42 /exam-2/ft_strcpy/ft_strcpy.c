/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:43:35 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 13:51:38 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

// int main(int argc, char **argv)
// {
// 	char dest[1000];
// 	char *src = "Ceci permet de decouvrir le fonctionnement de ton ft_strcpy.";
// 	printf("Result: %s\n", ft_strcpy(src, dest));
// 	return (0);
// }