/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:02:23 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/24 00:45:37 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	current_index(node *stack)
{
	int	i; //To store the index of the current node
	int	median; //To store the position of the median of the stack

	i = 0; //The first index is `0`
	if (!stack) //Check for am empty stack
		return ;
	median = stack_len(stack) / 2; //Calculate the median by dividing the length of a stack by 2
	while (stack) //Loop through all the nodes until the end of the stack is reached
	{
		stack->index = i; //Assign the current index value to the current node
		if (i <= median) //Check whether the current node is above or below the median
			stack->above_median = true; //If above, set the above_median data of the node to true
		else
			stack->above_median = false; //If below, set the above_median data of the node to false
		stack = stack->next; //Move to the next node for indexing
		++i; //Increment the index value to set the next node with
	}
}

static void	set_target_a(node *a, node *b)
{
	node	*current_b;
	node	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		target_node = NULL; // 🔥 Inicializa para evitar valores lixo

		current_b = b;
		while (current_b)
		{
			// 🔍 Encontra o maior número menor que `a->nbr`
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}

		// 🚨 Se nenhum menor foi encontrado, usar o maior número de `b`
		if (!target_node)
		{
			target_node = find_max(b);
			if (!target_node) // 🔴 Se `b` estiver vazio, erro fatal!
			{
				ft_printf("❌ ERRO CRÍTICO: `b` está vazio! (a->nbr = %d)\n", a->nbr);
				exit(1);
			}
			ft_printf("⚠️  Nenhum menor encontrado, usando o maior (%d) para a->nbr = %d\n",
				target_node->nbr, a->nbr);
		}

		// ✅ Define o target para `a`
		a->target_node = target_node;
		// ft_printf("✅ Target definido: a->nbr = %d | target_node->nbr = %d\n", a->nbr, target_node->nbr);

		a = a->next;
	}
}


static void	cost_analysis_a(node *a, node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		// 🚨 Verifica se `a->target_node` está NULL
		if (!a->target_node)
		{
			// ft_printf("❌ ERRO: a->target_node está NULL para a->nbr = %d!\n", a->nbr);
			return;
		}

		// 🚨 Verifica se `a->target_node->index` é válido
		if (a->target_node->index < 0)
		{
			// ft_printf("❌ ERRO: index inválido em a->target_node (%d)!\n", a->target_node->nbr);
			return;
		}

		// ft_printf("🔹 Analisando a->nbr = %d | target_node->nbr = %d | target_index = %d\n",
			// a->nbr, a->target_node->nbr, a->target_node->index);
			
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(node *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	node	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(node *a, node *b)
{
	// ft_printf("✅ Iniciando current_index(a)...\n");
	// current_index(a);
	// ft_printf("✅ Iniciando current_index(b)...\n");
	current_index(b);

	// 🔍 Verificar conteúdo da pilha `b` antes de `set_target_a()`
	// ft_printf("📌 Verificando stack B antes de set_target_a:\n");
	// node *temp_b = b;
	// while (temp_b)
	// {
	// 	ft_printf("  🔹 b->nbr = %d\n", temp_b->nbr);
	// 	temp_b = temp_b->next;
	// }
	
	// ft_printf("✅ Iniciando set_target_a...\n");
	set_target_a(a, b);

	// ft_printf("✅ Iniciando cost_analysis_a...\n");
	cost_analysis_a(a, b);
	// ft_printf("✅ Iniciando set_cheapest...\n");
	set_cheapest(a);
	// ft_printf("✅ Finalizando init_nodes_a...\n");
}
