/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:04:31 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/19 23:08:42 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static  void    swap(node **stack)
{
    node *first;
    node *second;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *stack = second; 
}

void sa(node **a)
{
    swap(a);
    // ft_printf("sa\n");
}

void sb(node **b)
{
    swap(b);
    // ft_printf("sb\n");
}