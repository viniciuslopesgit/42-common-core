/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:44:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/23 21:04:33 by viniciuslop      ###   ########.fr       */
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
bool	erro_syntax(const char *str);
void	add_node(node **stack, int value);
bool    error_duplicate(node *stack_a, int nbr);

// Stack
node    *create_node(int nbr);
void    init_stack_a(node **stack_a, char **argv);
bool    is_sorted(node *stack);
int     stack_len(node *stack);
node	*find_last(node *stack);
// Commands
void    sa(node **a, bool print);
void    sb(node **b, bool print);
void    ss(node **a, node **b, bool print);
void    pa(node **a, node **b, bool print);
void    pb(node **a, node **b, bool print);
void    ra(node **a, bool print);
void    rb(node **b, bool print);
void    rr(node **a, node **b, bool print);
void    rra(node **a, bool print);
void    rrb(node **b, bool print);
void    rrr(node **a, node **b, bool print);
// Sorted
void    sort_three(node **a);
node	*find_max(node *stack);



#endif