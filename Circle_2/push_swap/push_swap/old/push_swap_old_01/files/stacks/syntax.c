/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:23:55 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/23 22:54:23 by viniciuslop      ###   ########.fr       */
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

void	free_stack(node **stack) //Define a function to free a stack if there are errors
{
	node	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	node	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;
}