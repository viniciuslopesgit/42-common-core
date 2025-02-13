/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:23:55 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 21:32:55 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_errors(node **stack_a)
{
	node *temp;

	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

bool	erro_syntax(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (true);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (true);
		i++;
	}
	return (false);
}

void	add_node(node **stack, int value)
{
	node *new_node;
	node *temp;

	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		free_errors(stack);
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

bool error_duplicate(node *stack_a, int nbr)
{
	if (!stack_a)
		return (0);
    while (stack_a)
    {
        if (stack_a->nbr == nbr)
            return true; // Número duplicado encontrado
        stack_a = stack_a->next;
    }
    return false; // Nenhum número duplicado
}