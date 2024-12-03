/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:43:38 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/02 23:06:51 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_putnumber(int num)
{
	char	*buffer;
	int		len;

	buffer = ft_itoa(num);
	if (!buffer)
		return (-1);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	return (len);
}
