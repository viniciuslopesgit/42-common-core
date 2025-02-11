/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercicio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:17:33 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/02/11 01:22:21 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

// Estrutura do nó
typedef struct No
{
    int dado;
    struct No *proximo;    
} No;

// Função para criar um novo nó
No *criarNo(int valor);
// Função para inserir no início do lista
void inserirInicio(No **cabeca, int valor);
// Função para inserir no final da lista
void inserirFinal(No **cabeca, int valor);
// Função para remover um elemento da lista
void removerElemento(No **cabeca, int valor);
// Função para exibir lista
void exibirLista(No *cabeça);
// Função para liberar toda a lista da memória
void liberarLista(No ** cabeça);

// Função principal (testando a lista)
int main() {
    No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    printf("Lista atual: ");
    exibirLista(lista);

    // system("pause");
    getchar();

    printf("\nRemovendo o elemento 20...\n");
    removerElemento(&lista, 20);
    exibirLista(lista);

    liberarLista(&lista);
    printf("\nLista liberada.\n");

    return 0;
}

// Função para criar um novo nó
No *criarNo(int valor)
{
    No *novo = (No*)malloc(sizeof(No)); // Aloca memória para o novo nó
    if (novo)
    {
        novo->dado = valor;
        novo->proximo = NULL;
    }
    return novo;
}

// Função para inserir no início da lista
void inserirInicio(No **cabeca, int valor)
{
    No *novo = criarNo(valor);
    if (novo)
    {
        novo->proximo = *cabeca; // O novo nó aponta para a antiga cabeça
        *cabeca = novo; // Atualiza a cabeça da lista
    }
}

// Função para inserir no final da lista
void inserirFinal(No **cabeca, int valor)
{
    No *novo = criarNo(valor);
    if (!novo)
        return;
    if (*cabeca == NULL) // Se a lista estiver vazia
        *cabeca = novo;
    else
    {
        No *temp = *cabeca;
        while (temp->proximo != NULL) // Percorre até o final
        {
            temp = temp->proximo;
        }
        temp->proximo = novo; // Adiciona o novo nó ao fina
    }
}

// Função para remover um elemento da lista
void removerElemento(No **cabeca, int valor)
{
    No *temp = *cabeca;
    No *anterior = NULL;
    
    while(temp != NULL && temp->dado != valor) // Busca o elemento
    {
        anterior = temp;
        temp = temp->proximo;
    }
    if (temp == NULL)
        return;
    if (anterior == NULL)
        *cabeca = temp->proximo;
    else
    {
        anterior->proximo = temp->proximo; // remove o nó
    }
    free(temp);
}

// Função para exibir a lista
void exibirLista(No *cabeca)
{
    No *temp = cabeca;
    while (temp != NULL)
    {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para liberar toda a lista da memória
void liberarLista(No **cabeca)
{
    No *temp;
    while (*cabeca != NULL)
    {
        temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
    }
    free(temp);
}