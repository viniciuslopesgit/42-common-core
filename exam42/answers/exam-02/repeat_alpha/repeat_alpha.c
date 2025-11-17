/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:55:31 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/20 23:42:02 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;
		int count = 0;

		while(str[i])
		{
			count = 0;
			if (str[i] >= 'A' && str[i] <= 'Z')
				count = str[i] - 65;
			else if (str[i] >= 'a' && str[i] <= 'z')
				count = str[i] - 97;
			while(count + 1)
			{
				write(1, &str[i], 1);
				count--;
			}
			i++;
		}
	}
	write(1, "\n", 1);

	return 0;
}