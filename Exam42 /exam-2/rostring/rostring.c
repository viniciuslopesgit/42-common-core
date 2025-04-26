/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:41:14 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/06 20:41:15 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int count_words(char *str)
{
	int words = 0;
	int i = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			words++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
	}
	return (words);
}

void	print_rotate(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int words = count_words(str);

	if (words == 0)
		return;

	// Pega a primeira palavra
	while (is_space(str[i]))
		i++;
	start = i;
	while (str[i] && !is_space(str[i]))
		i++;
	end = i;

	// Imprime o resto da string
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i])
		{
			while (str[i] && !is_space(str[i]))
				write(1, &str[i++], 1);
			if (str[i]) // Só adiciona espaço se houver mais palavras no resto
				write(1, " ", 1);
		}
	}

	// Imprime a primeira palavra no fim
	if (words > 1) // Se houver mais de uma palavra, adiciona espaço antes
		write(1, " ", 1);
	while (start < end)
		write(1, &str[start++], 1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	print_rotate(argv[1]);
	write(1, "\n", 1);
	return (0);
}