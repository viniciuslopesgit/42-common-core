/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:34:09 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 17:38:03 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str 	= argv[1];
		int i 		= 0;
		
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}