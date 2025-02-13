/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:21:24 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 21:49:48 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool is_sorted(node *stack)
{
    if (!stack || !stack->next)
        return true;

    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
        {
             return false;
        }
        stack = stack->next;
    }
    
    return true;
}