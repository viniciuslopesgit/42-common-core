/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:39:20 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/22 19:15:27 by vilopes          ###   ########.fr       */
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
	if (argv < 2)
		printf("ft_strlen(%s): %i\n",argv[1], ft_strlen(argv[1]));
	return (0);
}
*/