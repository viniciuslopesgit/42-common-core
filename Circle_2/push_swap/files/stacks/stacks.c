/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:26:29 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 21:33:03 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static void append_node(node **stack_a, int nbr)
{
    node *new_node = create_node(nbr);
    node *last_node;

    if (!new_node)
    {
        while (*stack_a) // Libera memória em caso de erro
        {
            node *temp = *stack_a;
            *stack_a = (*stack_a)->next;
            free(temp);
        }
        return;
    }

    if (*stack_a == NULL) // Se a pilha estiver vazia, adiciona o primeiro nó
    {
        *stack_a = new_node;
    }
    else
    {
        last_node = *stack_a;
        while (last_node->next) // Encontra o último nó
            last_node = last_node->next;
        last_node->next = new_node; // Liga o último nó ao novo nó
        new_node->prev = last_node;
    }
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


