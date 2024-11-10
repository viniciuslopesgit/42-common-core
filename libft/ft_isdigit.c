/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:03:00 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:20:10 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	// ft_isdigit: Verifica se todos os valores sao numeros.
	if (argc < 2)
		return (1);
	printf("ft_isdigit(%c): %i\n", argv[1][0], ft_isdigit(argv[1][0]));
	return (0);
}
*/