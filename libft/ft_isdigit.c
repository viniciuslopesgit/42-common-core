/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:03:00 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/22 16:33:59 by vilopes          ###   ########.fr       */
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
	if (argc < 2)
		return (1);
	printf("ft_isdigit(%c): %i\n", argv[1][0], ft_isdigit(argv[1][0]));
	return (0);
}
*/