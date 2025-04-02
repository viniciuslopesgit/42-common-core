/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:21:30 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/20 01:03:41 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void    reverse_rotate(node **stack)
{
    node *last;
    node *second_last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    while(last->next) // Percorre até o penúltimo nó
        last = last->next;
    second_last = last->prev; // O penúltimo nó
    second_last->next = NULL; // Desconecta o último nó da pilha
    last->prev = NULL; // O último nó não aponta mais para o penúltimo nó
    last->next = *stack; // O último nó aponta para o topo da pilha
    (*stack)->prev = last; // O topo da pilha aponta para último nó
    *stack = last;
}

void    rra(node **a, bool print)
{
    reverse_rotate(a);
    if (print)
        ft_printf("rra\n");
}

void    rrb(node **b, bool print)
{
    reverse_rotate(b);
    if (print)
        ft_printf("rrb\n");

}

void    rrr(node **a, node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (print)
        ft_printf("rrr\n");
}