/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:24:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 01:42:26 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

#include "push_swap.h"

void    init_stack_a(node **stack_a, char **argv);
void	free_errors(node **stack_a);
long	ft_atol(const char *str);
bool	erro_syntax(const char *str);
void	add_node(node **stack, int value);
bool error_duplicate(node *stack_a, int nbr);

#endif