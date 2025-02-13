/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:43:49 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/13 01:58:41 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/stacks.h"

int	main(int argc, char **argv)
{
	node	*a;
	node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2 && argv[1][0])
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1); // argv + 1 para ignorar o nome do programa argv[0]
	node *current = a; // Ponteiro para o topo da pilha
	while (current)
	{
		ft_printf("%d\n", current->nbr);
		current = current->next;
	}
	while (a) // Liberar memoria apos o uso
	{
		node *current = a; // Ponteiro para o topo da pilha
		a = a->next;
		free(current);
	}
	ft_printf("_ _\n");
	ft_printf("a b\n\n");

	return (0);
}
