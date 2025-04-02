/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:24:25 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/01 21:53:50 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "push_swap.h"

void	init_stack_a(t_node **stack_a, char **argv);
void	free_errors(t_node **stack_a);
bool	error_syntax(const char *str);
int		error_duplicate(t_node *a, int n);
int		stack_len(t_node *stack);

#endif
