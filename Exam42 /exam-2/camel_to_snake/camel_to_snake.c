/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:40:27 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 17:48:50 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		char *str 	= argv[1];
		int i 		= 0;
	
		while(str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				write(1, &str[i], 1);
			else
			{
				str[i] = str[i] + 32;
				write(1, "_", 1);
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}