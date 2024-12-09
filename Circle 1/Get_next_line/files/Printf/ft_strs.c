/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:59:15 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/09 21:51:30 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int long *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int long *len)
{
	int long	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i], len);
		i++;
	}
}
