/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:35:45 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:18:41 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int main(int argc, char **argv)
{
	// isalnum: Verifica se todos os sao numeros
	if (argc < 2)
		return (1);
	printf("ft_isalnum(%c): %i\n", argv[1][0], ft_isalnum(argv[1][0]));
	return (0);
}
*/