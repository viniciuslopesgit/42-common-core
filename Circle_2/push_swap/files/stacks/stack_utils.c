/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:53:02 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/23 20:34:15 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

node	*find_last(node *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}


node	*find_max(node *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	node	        *max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->nbr; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}