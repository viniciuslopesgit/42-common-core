/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:46:04 by vilopes           #+#    #+#             */
/*   Updated: 2024/10/25 21:26:53 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{

	if (argc < 2)
		return (1);
	
	//ft_isalpha
	printf("ft_isalpha(%c): %i\n", argv[1][0], ft_isalpha(argv[1][0]));
	
	//ft_isdigit
	printf("ft_isdigit(%c): %i\n", argv[1][0], ft_isdigit(argv[1][0]));
	
	//ft_isalnum
	printf("ft_isalnum(%c): %i\n", argv[1][0], ft_isalnum(argv[1][0]));
	
	//ft_isacii
	printf("ft_isascii(%c): %i\n", argv[1][0], ft_isascii(argv[1][0]));
	printf("ft_isascii(200): %i\n", ft_isascii(200));

	//ft_isprint
	printf("ft_isprint(b): %i\n", ft_isprint('b'));
	printf("ft_isprint('\\n'): %i\n", ft_isprint('\n'));

	//ft_strlen
	printf("ft_strlen(%s): %i\n",argv[1], ft_strlen(argv[1]));
	
	//ft_memset
	char buffer[10];
	ft_memset(buffer, argv[1][0], sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = '\0';
	printf("ft_memset(%c): %s\n", argv[1][0], buffer);
	
	//ft_bzero
	ft_bzero(buffer, sizeof(buffer));
	printf("ft_bzero(%c): %s Buffer zerado!\n", argv[1][0], buffer);
	
	//VARIABLES
	char src[] = "Hello, World!";
	char dest[20];
	size_t size = 16;

	//ft_memcpy	
	ft_memcpy(dest, src, sizeof(src));
	printf("ft_memcpy(%s): %s\n", src, dest);

	//ft_memmove
	ft_memmove(dest, src, sizeof(src));
	printf("ft_memmove(%s): %s\n", src, dest);

	//ft_strlcpy
	ft_strlcpy(dest, src, size);
	if (!size)
		printf("ft_strlcpy: %zu\n", ft_strlcpy(dest, src, size));
	else
		printf("ft_strlcpy(%s): %s\n", src, dest);

	//ft_strlcat
	char dest01[] = "cachorro, ";
	ft_strlcat(dest01, argv[1], size);
	if (size > sizeof(argv[1]))
		printf("ft_strlcat(%s): %s\n", argv[1], dest01);
	else
		printf("ft_strlcat: %zu\n", ft_strlcat(dest01, argv[1], size));

	//ft_toupper
	printf("ft_toupper(%c): %c\n", argv[1][0], ft_toupper(argv[1][0]));

	//ft_tolower
	printf("ft_tolower(%c): %c\n", argv[1][0], ft_tolower(argv[1][0]));

	//ft_strchr
	printf("ft_strchr(%s): %s\n", argv[1], ft_strchr(argv[1], argv[1][0]));

	//ft_strrchr



	return (0);

}
