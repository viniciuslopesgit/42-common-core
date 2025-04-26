/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:48:48 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 11:02:17 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int j = 0;
		char *str = argv[1];

		while(str[i])
		{
			if (str[i] == ' ' && (str[i + 1] >= 33 && str[i + 1] <= 126))
				j = i + 1;
			i++;
		}
		while (str[j] >= 33 && str[j] <= 126)
		{
			write(1, &str[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}