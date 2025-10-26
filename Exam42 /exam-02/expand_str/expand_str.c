/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:49:07 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/03 14:53:08 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		char *str = argv[1];
		int flag = 0;

		int i = 0;
		while(str[i] == ' ' || str[i] == '\t')
			i++;
		while(str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
				flag = 1;
			else
			{
				if (flag)
					write(1, "   ", 3);
				flag = 0;
				ft_putchar(str[i]);
			}
			i++;
		}
	}
	ft_putchar('\n');	
	return 0;
}