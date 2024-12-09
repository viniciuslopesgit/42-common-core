/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:38:11 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/10 21:26:16 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
/*
int	main(int argc, char **argv)
{
	// ft_putendl_fd: Escreve uma string seguida de um nova linha.
	ft_putendl_fd("hello", 1);
	return (0);
}
*/