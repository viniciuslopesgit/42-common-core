/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:39 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:19:28 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isupper(int c)
{
	if (!(c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

static	int	islower(int c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	return (isupper(c) || islower(c));
}
/*
int	main(int argc, char **argv)
{
	// ft_isalpha: Verifica se todos os valores fazem parte do alfabeto
	if (argc < 2)
		return (1);
	printf("ft_isalpha(%c): %i\n", argv[1][0], ft_isalpha(argv[1][0]));
	return (0);
}
*/