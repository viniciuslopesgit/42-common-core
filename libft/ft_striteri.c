/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:57 by codespace         #+#    #+#             */
/*   Updated: 2024/11/10 22:06:38 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ft_putchar(unsigned int i, char *c)
{
	write(1, c, 1);
}

int	main(int argc, char **argv)
{
	// ft_striteri: aplica uma funcao fornecida a cada char
	// passando o indice desse char como argumento para essa funcao.
	if (argc == 2)
	{
		ft_striteri(argv[1], ft_putchar);
	}
	return (0);
}
*/