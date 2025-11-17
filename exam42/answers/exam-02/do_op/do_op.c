/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:04:00 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/12/12 16:18:51 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	add(int num1, int num2)
{
	return (num1 + num2);
}
int	sub(int num1, int num2)
{
	return (num1 - num2);
}
int	multi(int num1, int num2)
{
	return (num1 * num2);
}
int	divi(int num1, int num2)
{
	return (num1 / num2);
}
int	mod(int num1, int num2)
{
	return (num1 % num2);
}
int	main(int ac, char **av)
{
	int num1;
	int num2;
	int result;

	if (ac == 4)
	{
		num1 = atoi(av[1]);
		num2 = atoi(av[3]);
		if (av[2][0] == '+')
			result = add(num1, num2);

		else if (av[2][0] == '-')
			result = sub(num1, num2);

		else if (av[2][0] == '/')
			result = divi(num1, num2);

		else if (av[2][0] == '%')
			result = mod(num1, num2);

		else if (av[2][0] == '*')
			result = num1 * num2;

		printf("%d", result);
	}
	printf("\n");
}
