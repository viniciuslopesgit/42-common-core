/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:43:49 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/14 19:08:20 by viniciuslop      ###   ########.fr       */
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
	node *current = a; // Ponteiro para o topo da pilha
	if (!is_sorted(a))
        ft_printf("Nao esta ordenado\n\n");
	else
        ft_printf("Esta ordenado\n\n");
	
	
	while (current) // Impreme stacks 'a' e 'b'
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