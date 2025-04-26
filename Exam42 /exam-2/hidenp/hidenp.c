/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:01:45 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 14:36:20 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *word = argv[1];
		char *str = argv[2];
		int i = 0;
		int j = 0;
		while (word[i] && str[j])
		{
			if (word[i] == str[j])
				i++;
			j++;
		}
		if (word[i] == '\0')
			write(1, "1", 1 );
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}