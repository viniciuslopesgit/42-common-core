/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:43:33 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/20 01:04:34 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void     rotate(node **stack)
{
    node *first;
    node *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack; // Guarda o primeiro no
    *stack = first->next; // Move o topo para o segundo nó
    (*stack)->prev = NULL;
    last = *stack;
    while (last->next) // Percorre até o ultimo nó
        last = last->next;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void    ra(node **a, bool print)
{
    rotate(a);
    if (print)
       printf("ra\n");
}
void    rb(node **b, bool print)
{
    rotate(b);
    if (print)
        printf("rb\n");
}

void    rr(node **a, node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (print)
        ft_printf("rr\n");
}