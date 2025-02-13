/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:26:29 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/12 23:57:52 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stacks.h"
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

void init_stack_a(node **stack_a, char **argv)
{
    int i = 0;
    node *new_node;
    node *last_node = NULL;

    while (argv[i])
    {
        int nbr = ft_atoi(argv[i]);
        new_node = create_node(nbr);
        if (!new_node)
        {
            while (*stack_a) // Se a alocacao falhar, libera a memoria previamente alocada
            {
                node *temp = *stack_a;     // Guarda o ponteiro do no atual
                *stack_a = (*stack_a)->next; // Move o ponteiro da pilha para o proximo no
                free(temp);                  // libera memoria
            }
            return;
        }
        if (*stack_a == NULL)
            *stack_a = new_node;
        else
        {
            last_node->next = new_node;  // O no anterior aponta para o novo no
            last_node->prev = last_node; // O novo no aponta para o anterior
        }
        last_node = new_node; // Atualiza o utimo no inserido
        i++;
    }
}