/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:59:39 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/22 15:59:49 by vilopes          ###   ########.fr       */
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
	if (argc < 2)
		return (1);
	printf("ft_isalpha(%c): %i\n", argv[1][0], ft_isalpha(argv[1][0]));
	return (0);
}
*/