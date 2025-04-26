/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:30:03 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/04/20 13:25:10 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
	int i = 0;
	int words = 0;
	while (str[i])
	{
		while(str[i] && is_separator(str[i]))
			i++;
		if (str[i] && !is_separator(str[i]))
		{
			words++;
			while(str[i] && !is_separator(str[i]))
				i++;
		}
	}
	return(words);
}

char *malloc_word(char *src, int len)
{
	// Copia exatamete o número de letras da palavra e adiciona \0 no fim
	int i = 0;
	char *word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	int i = 0;
	int	word = 0;
	int start = 0;
	char **result;

	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_separator(str[i]))
			i++;
		if (str[i] && !is_separator(str[i]))
		{
			start = i;
			while (str[i] && !is_separator(str[i]))
				i++;
			// Armazena cada palavra
			result[word++] = malloc_word(&str[start], i - start);
		}
	}
	result[word] = NULL;
	return (result);
}

// int main(int argc, char **argv)
// {

// 	char *text = "    Hello\n, Word! 42";
// 	char **words = ft_split(text);
// 	int i = 0;
// 	while (words[i])
// 	{
// 		printf("words[%d] = \"%s\"\n", i, words[i]);
// 		free(words[i]);
// 		i++;
// 	}
// 	free(words);
	
// 	return (0);
// }

// ✅ Parte 1: Entendendo o problema
// Antes de codar qualquer coisa, precisamos entender bem o que o enunciado quer:

// 📌 O que a função ft_split deve fazer?

// Recebe uma string como argumento (ex: "hello world 42").
// Divide essa string em palavras, separando pelos seguintes delimitadores:
// espaço (' ')
// tabulação ('\t')
// quebra de linha ('\n')
// Retorna um array de strings (char **) com as palavras separadas.
// O array deve terminar com um ponteiro NULL (char *last = NULL) pra indicar fim do array.
// 📌 Exemplo de entrada/saída:

// char **result = ft_split("  Hello\tWorld \n42");

// result[0] -> "Hello"
// result[1] -> "World"
// result[2] -> "42"
// result[3] -> NULL
// 🔍 Coisas importantes pra lembrar:
// Vamos ignorar múltiplos espaços/tabs/\n seguidos.
// Só podemos usar malloc. Ou seja: sem strtok, sem strdup, sem outras funções externas.
// Temos que alocar dinamicamente espaço pros ponteiros (array de palavras) e pros caracteres (as palavras em si).


// ✅ Parte 2: Planejamento e Lógica da Função
// Antes de escrever código, precisamos pensar como resolver isso passo a passo, tipo um algoritmo. Aqui está o plano:

// 📋 Etapas que a função ft_split precisa seguir:
// 1. Contar quantas palavras tem na string

// Pra saber quantos ponteiros (palavras) vamos precisar no array.
// Exemplo: " oi tudo bem " → 3 palavras.
// 2. Alocar memória pro array de ponteiros

// Um ponteiro para cada palavra.
// +1 ponteiro final que será NULL.
// 3. Percorrer a string novamente

// Pular os delimitadores (espaços, tabs, quebras de linha).
// Quando achar uma palavra:
// Contar o tamanho da palavra.
// Alocar memória pra ela.
// Copiar os caracteres.
// Avançar até o próximo delimitador.
// 4. Finalizar com um ponteiro NULL no array

// Assim sabemos onde a lista de palavras termina.
// 💡 Resumo visual:
// Input:   "  ola  mundo\n42"
// Etapas:
// 1. Contar palavras -> 3
// 2. Alocar array com 4 ponteiros (3 palavras + NULL)
// 3. Copiar palavras uma por uma
// 4. Retornar o array

// ✅ Parte 3: Função para contar palavras
// 📌 Lógica:

// Vamos percorrer a string caractere por caractere.
// Sempre que encontrarmos um início de palavra (ou seja, um caractere que não é espaço, tab ou \n), contamos uma nova palavra.
// Continuamos até achar um delimitador, e repetimos o processo.