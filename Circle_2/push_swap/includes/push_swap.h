/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:44:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 22:05:28 by vilopes          ###   ########.fr       */
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
void    sa(node **stack_a);

#endif