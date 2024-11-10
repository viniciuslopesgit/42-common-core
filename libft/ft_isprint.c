/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:22:05 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/22 17:26:45 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isprint(b): %i\n", ft_isprint('b'));
	printf("ft_isprint('\\n'): %i\n", ft_isprint('\n'));
	return (0);
}
*/