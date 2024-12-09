/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:36:17 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:56:12 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (c);
	c = c - 32;
	return (c);
}
/*
int main(int argc, char **argv)
{
	// ft_toupper: Converte char para maiusculo.
	if (argc < 2)
		return (0);
	printf("ft_toupper(%c): %c\n", argv[1][0], ft_toupper(argv[1][0]));
	return (0);
}
*/