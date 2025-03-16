/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:43:49 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/24 00:47:24 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void imprime(node *a, node *b)
{
	node *current_a = a; // Ponteiro para o topo da pilha
	node *current_b = b;
	
	current_a = a;
	current_b = b;
	while (current_a || current_b) // Enquanto pelo menos uma pilha tiver elementos
	{
		if (current_a) // Se houver elementos em 'a', imprime
		{
			ft_printf("%d ", current_a->nbr);
			current_a = current_a->next;
		}
		else
			ft_printf("	"); // Espaço para alinhar caso 'a' tenha menos elementos que 'b'
		if (current_b) // Se houver elementos em 'b', imprime
		{
			ft_printf("%d", current_b->nbr);
			current_b = current_b->next;
		}
		ft_printf("\n"); // Quebra de linha após imprimir uma linha da pilha
	}

	ft_printf("_ _\n");
	ft_printf("a b\n\n");
}

int	main(int argc, char **argv)
{
	node	*a;
	node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	else
		ft_printf("Está ordenado\n");
	// imprime(a, b);
	
	///////////////////////////////////////////////////////////
	//						FREE MEMORY 					 //
	///////////////////////////////////////////////////////////
	free_stack(&a);
	return (0);
}