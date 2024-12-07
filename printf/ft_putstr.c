/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:47:51 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/07 21:11:39 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	unsigned long	len;

	if (!str)
	{
		write(1, "(null)", 6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
