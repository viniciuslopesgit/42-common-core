/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:15:43 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/06/10 18:40:14 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	char *str = argv[1];
	int i = 0;
	int start = 0;
	int end = 0;
	int printed = 0;

	while(str[i] && is_space(str[i]))
		i++;
	
	start = i;
	while(str[i] && !is_space(str[i]))
		i++;
	end = i;
	
	while(str[i])
	{
		if (str[i] && is_space(str[i]))
		{
			while(is_space(str[i]))
				i++;
		}
		if (str[i])
		{
			if (printed)
				write(1, " ", 1);
			while(str[i] && !is_space(str[i]))
			{	write(1, &str[i], 1);
				i++;
			}
			printed = 1;
		}
	}
	if (printed)
		write(1, " ", 1);
	while(start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);

	return 0;
}