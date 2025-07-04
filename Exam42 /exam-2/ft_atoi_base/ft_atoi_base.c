/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:52:06 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/05/21 00:23:13 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_isvalid(char c, int base)
{
	char dig1[17] = "0123456789abcdef";
	char dig2[17] = "0123456789ABCDEF";
	
	int i = 0;
	while(i < base)
	{
		if (dig1[i] == c || dig2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while(ft_isvalid(str[i], str_base))
	{
		result = (result * str_base) + (ft_value(str[i]));
		i++;
	}

	return (result * sign);
}
