/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:39:20 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:34:35 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
		s++;
	return (s);
}
/*
int main (int argc, char **argv)
{
	// ft_strlen: Calcula o tamanho de um str.
	if (argv < 2)
		printf("ft_strlen(%s): %i\n",argv[1], ft_strlen(argv[1]));
	return (0);
}
*/