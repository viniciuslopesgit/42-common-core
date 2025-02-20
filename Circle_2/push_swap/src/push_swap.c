/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:43:49 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/20 01:18:24 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	node	*a;
	// node	*b;

	a = NULL;
	// b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1; // argv + 1 para ignorar o nome do programa argv[0]
	init_stack_a(&a, argv);

	///////////////////////////////////////////////////////////
	//						 OPERAÇÕES 						 //
	///////////////////////////////////////////////////////////
	
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
	}
	
	///////////////////////////////////////////////////////////
	//						DEBUG PRINTF 					 //
	///////////////////////////////////////////////////////////
	// node *current_a = a; // Ponteiro para o topo da pilha
	// node *current_b = b;
	
	// current_a = a;
	// current_b = b;
	// while (current_a || current_b) // Enquanto pelo menos uma pilha tiver elementos
	// {
	// 	if (current_a) // Se houver elementos em 'a', imprime
	// 	{
	// 		ft_printf("%d ", current_a->nbr);
	// 		current_a = current_a->next;
	// 	}
	// 	else
	// 		ft_printf("	"); // Espaço para alinhar caso 'a' tenha menos elementos que 'b'
	// 	if (current_b) // Se houver elementos em 'b', imprime
	// 	{
	// 		ft_printf("%d", current_b->nbr);
	// 		current_b = current_b->next;
	// 	}
	// 	ft_printf("\n"); // Quebra de linha após imprimir uma linha da pilha
	// }

	// ft_printf("_ _\n");
	// ft_printf("a b\n\n");

	///////////////////////////////////////////////////////////
	//						FREE MEMORY 					 //
	///////////////////////////////////////////////////////////
	while (a) // Liberar memoria apos o uso
	{
		node *current_a = a; // Ponteiro para o topo da pilha
		a = a->next;
		free(current_a);
	}
	return (0);
}


// ✓✓✓ Declare ponteiros para duas estruturas de dados/listas ligadas, uma para a pilha `a` e outra para `b`
	// ✓✓✓ Definir ambos os ponteiros para NULL para evitar comportamento indefinido e indicar que estamos a começar com pilhas vazias

// ✓✓✓ Lidar com erros de contagem de entrada. O número de argumentos deve ser 2 ou mais, e a segunda entrada não deve estar vazia
	// ✓✓✓ Se houver erros de entrada, devolve erro

// ✓✓✓ Tratar ambos os casos de entrada, seja um número variável de argumentos de linha de comando, ou como uma string
	// ✓✓✓ Se a entrada de números for como uma string, chamar split() para dividir as substrings

// ✓✓✓ Inicializar a pilha `a` anexando cada número de entrada como um nó à pilha `a`
	// ✓✓✓ Lidar com estouro de números inteiros, duplicatas e erros de sintaxe, por exemplo, a entrada deve conter apenas dígitos, ou sinais `-` `+`
		// ✓✓✓ Se forem encontrados erros, libera a pilha `a` e retorna o erro
	// ✓✓✓ Verifica para cada entrada, se é um inteiro longo
		// ✓✓✓ Se a entrada é uma string, converte-a para um inteiro longo 
	//Apagar os nós à pilha `a`

// Verificar se a pilha `a` está ordenada
	//Se não estiver ordenada, implementar o nosso algoritmo de ordenação 
		// Verificar se existem 2 números
			//Em caso afirmativo, basta trocar os números
		// Verificar se há 3 números
			//Se sim, implementar o nosso algoritmo simples `sort três
		// Verificar se a pilha tem mais de 3 números
			//Se sim, implementar o nosso algoritmo do Turk

//Limpar a pilha