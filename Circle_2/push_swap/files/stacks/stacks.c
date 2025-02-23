/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:26:29 by vilopes           #+#    #+#             */
/*   Updated: 2025/02/23 21:03:53 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) // Ignora espaços e caracteres de controle
        i++;

    if (str[i] == '-' || str[i] == '+') // Lida com o sinal
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') // Converte os caracteres numéricos
    {
        if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && str[i] - '0' > LONG_MAX % 10)) 
        {
            // Verifica se o próximo passo causaria overflow
            return (sign == 1) ? LONG_MAX : LONG_MIN;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}


static void append_node(node **stack_a, int nbr)
{
    node *new_node = create_node(nbr);
    node *last_node;

    if (!new_node)
    {
        while (*stack_a) // Libera memória em caso de erro
        {
            node *temp = *stack_a;
            *stack_a = (*stack_a)->next;
            free(temp);
        }
        return;
    }

    if (*stack_a == NULL) // Se a pilha estiver vazia, adiciona o primeiro nó
    {
        *stack_a = new_node;
    }
    else
    {
        last_node = *stack_a;
        while (last_node->next) // Encontra o último nó
            last_node = last_node->next;
        last_node->next = new_node; // Liga o último nó ao novo nó
        new_node->prev = last_node;
    }
}

node *create_node(int nbr)
{
    node *new_node = (node *)malloc(sizeof(node)); // Aloca memoria para cada no
    if (!new_node)
    {
        return NULL;
        ft_printf("create_node: erro");
    }
    new_node->nbr = nbr;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void init_stack_a(node **stack_a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while(argv[i])
    {
        if(erro_syntax(argv[i]))
            free_errors(stack_a);
        n = ft_atol(argv[i]); // Converte o str para int long
        if (n > INT_MAX || n < INT_MIN)
            free_errors(stack_a);
        if (error_duplicate(*stack_a, (int)n))
            free_errors(stack_a);
        append_node(stack_a, (int)n);
        i++;
    }
}

int stack_len(node *stack)
{
    int len;
    if (!stack)
        return (0);
    len = 0;
    while (stack)
    {
        stack = stack->next;
        len++;
    }
    return (len);
}