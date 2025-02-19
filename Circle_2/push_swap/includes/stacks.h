/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:24:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/19 20:53:41 by viniciuslop      ###   ########.fr       */
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
bool    error_duplicate(node *stack_a, int nbr);

#endif