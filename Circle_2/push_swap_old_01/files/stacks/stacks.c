/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:26:29 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/23 23:55:07 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) // Ignora espaços e caracteres de controle
        i++;

    if (str[i] == '-' || str[i] == '+') // Lida com o sinal
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') // Converte os caracteres numéricos
    {
        if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && str[i] - '0' > LONG_MAX % 10)) 
        {
            // Verifica se o próximo passo causaria overflow
            return (sign == 1) ? LONG_MAX : LONG_MIN;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    // Certifique-se de que não há caracteres não numéricos após o número
    if (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) 
        return 0; // Ou algum valor de erro que você possa tratar

    return result * sign;
}

static void append_node(node **stack, int n) // Define a function that searches for the last node to append to the linked list
{
    node *new_node; // To store a pointer to the new node to be created with the value `n`
    node *last_node; // To store a pointer to the current last node of the stack

    if (!stack)
        return ;
    
    new_node = malloc(sizeof(node)); // Allocate memory for the new node
    if (!new_node)
        return ;

    new_node->next = NULL; // Set the next pointer of the new node to NULL because it will be the last node in the list
    new_node->nbr = n; // Set the `nbr` data of the new node to `n` value
    new_node->cheapest = 0; // Initialize cheapest to 0

    // other elements in the struct could be initialized as well but for now, this was the only one causing a valgrind issue
    if (!(*stack)) // Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
    {
        *stack = new_node; // If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
        new_node->prev = NULL; // Set the head node's previous pointer to NULL as it's the first node
    }
    else // If the stack is not empty, it means there are existing nodes in the linked list
    {
        last_node = find_last(*stack); // In which case, find the last node
        last_node->next = new_node; // Append the new node to the last node
        new_node->prev = last_node; // Update the previous pointer of the new node and complete the appending
    }
}

node *create_node(int nbr)
{
    node *new_node = (node *)malloc(sizeof(node)); // Aloca memoria para cada no
    if (!new_node)
    {
        return NULL;
        ft_printf("create_node: erro");
    }
    new_node->nbr = nbr;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void init_stack_a(node **stack_a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while(argv[i])
    {
        if(erro_syntax(argv[i]))
            free_errors(stack_a);
        n = ft_atol(argv[i]); // Converte o str para int long
        if (n > INT_MAX || n < INT_MIN)
            free_errors(stack_a);
        if (error_duplicate(*stack_a, (int)n))
            free_errors(stack_a);
        append_node(stack_a, (int)n);
        i++;
    }
}

int stack_len(node *stack)
{
    int len;
    if (!stack)
        return (0);
    len = 0;
    while (stack)
    {
        stack = stack->next;
        len++;
    }
    return (len);
}

node	*get_cheapest(node *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(node **stack,
						node *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}