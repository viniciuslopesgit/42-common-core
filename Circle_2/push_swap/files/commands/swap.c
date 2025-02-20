/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:04:31 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/20 01:11:50 by viniciuslop      ###   ########.fr       */
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

void sa(node **a, bool print)
{
    swap(a);
    if (print)
        ft_printf("sa\n");
}

void sb(node **b, bool print)
{
    swap(b);
    if (print)
        ft_printf("sb\n");
}

void ss(node **a, node **b, bool print)
{
    swap(a);
    swap(b);
    if (print)
        ft_printf("ss\n");
}