/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:49:08 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/20 21:45:54 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	sum(int count, ...)
{
	int		result_sum;
	int		i;
	va_list	args;

	va_start(args, count);
	result_sum = 0;
	i = 0;
	while (i < count)
	{
		result_sum += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (result_sum);
}

int	main(void)
{
	printf("Sum result: %d\n", sum(4, 12, 3, 4, 5));
	return (0);
}
