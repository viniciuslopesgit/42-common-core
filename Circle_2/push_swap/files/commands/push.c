/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:04:52 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/19 22:46:51 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void push(node **from, node **to)
{
    node *temp;

    if (!from || !*from) // Verifica se a pilha de origem esta vazia
        return;
    temp = *from; // O primeiro no de 'from'
    *from = (*from)->next; // Move o topo para o proximo no
    if (*from)
        (*from)->prev = NULL;
    temp->next = *to; // Liga o no movido ao topo da pilha 'to'
    if (*to)
        (*to)->prev = temp;
    *to = temp; // Atualiza o topo da pilha 'to'
}

void pa(node **a, node **b)
{
    push(b, a);
    // ft_printf("pa\n");
}

void pb(node **a, node **b)
{
    push(a, b);
    // ft_printf("pb\n");
}
