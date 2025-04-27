/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                               feldt   +#+           */
/*   Created: 2025/04/27 00:29:48 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/27 01:19:56 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int g;

	if (a == 0 || b == 0)
		return 0;
	if (a > b)
		g = a;
	else
		g = b;
	while (1)
	{
		if ((g % a == 0) && (g % b == 0))
			return g;
		g++;
	}
}