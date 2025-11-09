/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:52:11 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/06 02:06:18 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int has_next_word(char *str, int i)
{
	while(str[i])
	{
		if (!is_space(str[i]))
			return 1;
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;
		
		while(str[i])
		{
			while(str[i] && is_space(str[i]))
				i++;
			while(str[i] && !is_space(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			if (has_next_word(str, i))
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}