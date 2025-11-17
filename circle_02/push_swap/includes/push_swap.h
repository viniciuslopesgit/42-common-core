/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:44:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/14 21:52:11 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct t_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct t_node	*target_node;
	struct t_node	*next;
	struct t_node	*prev;
}					t_node;

// Erros
long				ft_atol(const char *str);
int					error_syntax(char *str_n);
int					error_duplicate(t_node *a, int n);
void				free_stack(t_node **stack);
void				free_errors(t_node **a);
int					is_valid_number(char *str);

// Stack
t_node				*find_last(t_node *stack);
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);
bool				is_sorted(t_node *stack);
int					stack_len(t_node *stack);
void				min_on_top(t_node **a);
void				init_stack_a(t_node **stack_a, char **argv);
void				free_stack(t_node **stack);

// t_nodes
t_node				*get_cheapest(t_node *stack);
void				init_nodes_a(t_node *a, t_node *b);
void				init_nodes_b(t_node *a, t_node *b);
void				current_index(t_node *stack);
void				set_cheapest(t_node *stack);
void				prep_for_push(t_node **s, t_node *n, char c);

// Commands
void				sa(t_node **a, bool print);
void				sb(t_node **b, bool print);
void				ss(t_node **a, t_node **b, bool print);
void				pa(t_node **a, t_node **b, bool print);
void				pb(t_node **a, t_node **b, bool print);
void				ra(t_node **a, bool print);
void				rb(t_node **b, bool print);
void				rr(t_node **a, t_node **b, bool print);
void				rra(t_node **a, bool print);
void				rrb(t_node **b, bool print);
void				rrr(t_node **a, t_node **b, bool print);

// Sorted
void				sort_three(t_node **a);
void				sort_stacks(t_node **a, t_node **b);

#endif
