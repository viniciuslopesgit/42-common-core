/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:44:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/19 22:36:44 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct node
{
    int     nbr;
    struct node *next;
    struct node *prev;
} node;

// Handle erros
void	free_errors(node **stack_a);
long	ft_atol(const char *str);
bool	erro_syntax(const char *str);
void	add_node(node **stack, int value);
bool    error_duplicate(node *stack_a, int nbr);

// Stack initiation
void    init_stack_a(node **stack_a, char **argv);
// Commands
bool    is_sorted(node *stack);
void    swap_a(node **stack);
void    pa(node **a, node **b);
void    pb(node **a, node **b);

#endif