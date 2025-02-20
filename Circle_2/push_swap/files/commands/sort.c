/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:44:25 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/20 01:20:32 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    sort_three(node **a)
{
    node   *big_node; // Guarda o ponteiro de 'a'
    big_node = find_max(*a);
    if (big_node == *a)
        ra(a, true); //falta a bool como false;
    else if ((*a)->next == big_node)
        rra(a, true);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, true);
}