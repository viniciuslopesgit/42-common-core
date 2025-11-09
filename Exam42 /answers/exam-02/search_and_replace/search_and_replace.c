/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:52:57 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/12 21:59:35 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{

	if (argc == 4)
	{
		char *str = argv[1];
		char *s = argv[2];
		char *r = argv[3];
		

		int i = 0;
		while (s[i] || r[i])
			i++;
		if (i > 1)
		{
			write(1, "\n", 1);
			return 0;
		}

		i = 0;
		while(str[i])
		{
			if (str[i] == s[0])
				str[i] = r[0];
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	return 0;
}