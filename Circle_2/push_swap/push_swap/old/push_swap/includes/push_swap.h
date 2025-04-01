/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:44:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/24 02:46:00 by viniciuslop      ###   ########.fr       */
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
	int					nbr; //The number to sort
	int					index; //The number's position in the stack
	int					push_cost; //How many commands in total
	bool				above_median; //Used to calculate `push_cost`
	bool				cheapest; //The node that is the cheapest to do commands
	struct node	        *target_node; //The target node of a node in the opposite stack
	struct node	        *next; //A pointer to the next node
	struct node	        *prev; //A pointer to the previous node
} node;

// DEBUG
void imprime(node *a, node *b);

// Handle erros
int	    error_syntax(char *str_n);
int	    error_duplicate(node *a, int n);
void	free_stack(node **stack);
void	free_errors(node **a);

// Stack
bool    is_sorted(node *stack);
node    *create_node(int nbr);
void    init_stack_a(node **stack_a, char **argv);
int     stack_len(node *stack);
node	*find_last(node *stack);
node	*find_min(node *stack);
node	*find_max(node *stack);
void	free_stack(node **stack);

// Nodes
void	init_nodes_a(node *a, node *b);
void	init_nodes_b(node *a, node *b);
void	current_index(node *stack);
node	*get_cheapest(node *stack);
void	set_cheapest(node *stack); //Set the stack's cheapest node
void			prep_for_push(node **s, node *n, char c); //Define a function that moves the required node to the top of the stack


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
void	sort_stacks(node **a, node **b);



#endif