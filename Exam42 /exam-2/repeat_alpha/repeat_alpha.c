/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:24:53 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/21 23:53:25 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void repeat_alpha(char *str)
{
	int i 			= 0;
	int repeat 		= 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			repeat = str[i] - 65;
		else if (str[i] >= 'a' && str[i] <= 'z')
			repeat = str[i] - 97;
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			while(repeat >= 0)
			{
				write(1, &str[i], 1);
				repeat--;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}