/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:46:04 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/22 17:46:46 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	arg;

	arg = argv[1][0];
	if (argc < 2)
		return (1);
	printf("ft_isalphai(%c): %i\n", arg, ft_isalpha(arg));
	printf("ft_isdigit(%c): %i\n", arg, ft_isdigit(arg));
	printf("ft_isalnum(%c): %i\n", arg, ft_isalnum(arg));
	printf("ft_isascii(%c): %i\n", arg, ft_isascii(arg));
	printf("ft_isascii(200): %i\n", ft_isascii(200));
	printf("ft_isprint(b): %i\n", ft_isprint('b'));
	printf("ft_isprint('\\n'): %i\n", ft_isprint('\n'));
	printf("ft_strlen(%s): %i\n",argv[1], ft_strlen(argv[1]));
	return (0);
}
