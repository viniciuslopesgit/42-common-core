#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}



// t_list *create_node(int data)
// {
// 	t_list *node = (t_list *)malloc(sizeof(t_list));
// 	if (!node)
// 		return NULL;

// 	node->data = data;
// 	node->next = NULL;

// 	return node;
// }

// void add_node_final(t_list **list, int data)
// {
// 	t_list *node = create_node(data);
// 	if (!node)
// 		return;
// 	if (!*list)
// 	{
// 		*list = node;
// 		return;
// 	}
// 	// anda até o último nó
// 	t_list *current = *list;
// 	while(current->next)
// 		current = current->next;
// 	current->next = node;
// }

// void print_list(t_list *list)
// {
// 	while(list != NULL)
// 	{
// 		printf("%d", list->data);
// 		if (list->next != NULL)
// 			printf("->");
// 		list = list->next;
// 	}
// 	printf("\n");
// }

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }

// int main(int argc, char **argv)
// {
// 	t_list *list = NULL;

// 	add_node_final(&list, 5);
// 	add_node_final(&list, 2);
// 	add_node_final(&list, 3);
// 	add_node_final(&list, 1);

// 	printf("Lista original: ");
// 	print_list(list);

// 	sort_list(list, ascending);

// 	printf("Lista ordenada: ");
// 	print_list(list);

// 	return 0;
// }