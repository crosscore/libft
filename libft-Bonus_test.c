#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

//Bonus part
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	test_lstnew(void)
{
	int x = 42;
	t_list *new_node = ft_lstnew(&x);

	printf("Content of new node: %d\n", *((int *)new_node->content)); // Output: 42
	printf("Address of new node: %p\n", new_node->content);
	printf("Address of next node: %p\n", new_node->next); // Output: 0x0
	free(new_node);
	system("liaks -q a.out");
}

void	test_lstadd_front(void)
{
	t_list *first = (t_list *)malloc(sizeof(t_list));
	first->content = "First node";
	first->next = NULL;
	printf("Before:\n");
	printf("First node: %s\n", (char*)first->content);

	t_list *new = (t_list *)malloc(sizeof(t_list));
	new->content = "New node";
	new->next = NULL;
	printf("New node: %s\n", (char*)new->content);
	printf("------\n");
	printf("After:\n");
	ft_lstadd_front(&first, new);
	printf("First node after adding new node: %s\n", (char*)first->content);
	printf("Next node after adding new node: %s\n", (char*)first->next->content);
	free(first);
	system("liaks -q a.out");
}

void	test_lstsize(void)
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	int size;

	head = NULL;
	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = (void *)1;
	node1->next = NULL;
	head = node1;

	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = (void *)2;
	node2->next = NULL;
	node1->next = node2;

	node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = (void *)3;
	node3->next = NULL;
	node2->next = node3;

	size = ft_lstsize(head);
	printf("List size: %d\n", size);
	system("liaks -q a.out");
}

void	test_lstlast(void)
{
	t_list *first;
	t_list *second;
	t_list *third;

	first = (t_list *)malloc(sizeof(t_list));
	first->content = (void *)1;
	first->next = NULL;

	second = (t_list *)malloc(sizeof(t_list));
	second->content = (void *)2;
	first->next = second;

	third = (t_list *)malloc(sizeof(t_list));
	third->content = (void *)3;
	second->next = third;
	third->next = NULL;

	t_list *last = ft_lstlast(first);
	printf("Content of third node: %p\n", third->content);
	printf("Content of last node: %p\n", last->content);
	free(first);
	free(second);
	free(third);
	system("liaks -q a.out");
}

void	test_lstadd_back(void)
{
	t_list *list = NULL;
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = (void *)"Node 1";
	node1->next = NULL;
	ft_lstadd_back(&list, node1);

	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = (void *)"Node 2";
	node2->next = NULL;
	ft_lstadd_back(&list, node2);

	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = (void *)"Node 3";
	node3->next = NULL;
	ft_lstadd_back(&list, node3);

	t_list *temp = list;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	free(node1);
	free(node2);
	free(node3);
	system("leaks -q a.out");
}

void	del_content(void *content)
{
	free(content);
}

void	test_lstdelone(void)
{
	printf("start\n");
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = malloc(sizeof(int));
	*(int *)node1->content = 42;
	node1->next = NULL;

	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = malloc(sizeof(int));
	*(int *)node2->content = 45;
	node2->next = NULL;

	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = malloc(sizeof(int));
	*(int *)node3->content = 48;
	node3->next = NULL;

	node1->next = node2;
	node2->next = node3;
	printf("Before:\n");
	printf("%d\n", *(int *)node1->content);
	printf("%d\n", *(int *)node2->content);
	printf("%d\n", *(int *)node3->content);
	t_list *current_node = node1;
	ft_lstdelone(current_node, &del_content);
	printf("------\n");
	printf("After:\n");
	//printf("%d\n", *(int *)node1->content); //SEGV
	printf("%d\n", *(int *)node2->content);
	printf("%d\n", *(int *)node3->content);
	printf("Complete!\n");
	system("leaks -q a.out");
}

void	del_func(void *content)
{
	free(content);
}

void	test_lstclear(void)
{
	// Create a linked list
	t_list *first = malloc(sizeof(t_list));
	first->content = strdup("Node 1");
	first->next = malloc(sizeof(t_list));
	first->next->content = strdup("Node 2");
	first->next->next = malloc(sizeof(t_list));
	first->next->next->content = strdup("Node 3");
	first->next->next->next = NULL;

	// Print the original linked list
	t_list *current = first;
	printf("Before:\n");
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	// Clear the linked list
	ft_lstclear(&first, &del_func);

	// Print the cleared linked list
	printf("------\n");
	printf("After:\n");
	current = first;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("complete!\n");
	system("leaks -q a.out");
}

void	print_content(void *content)
{
	printf("content:%d\n", *(int *)content);
}

void	test_lstiter(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	int data1 = 1;
	node1->content = &data1;
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	int data2 = 2;
	node2->content = &data2;
	node2->next = NULL;

	node1->next = node2;

	ft_lstiter(node1, &print_content);
	free(node1);
	free(node2);
	system("leaks -q a.out");
}

void	*double_content(void *content)
{
	int *new_content;

	new_content = (int *)malloc(sizeof(int));
	*new_content = *(int *)content * 2;
	return (new_content);
}

void	free_content(void *content)
{
	free(content);
}

void	test_lstmap(void)
{
	t_list *list;
	t_list *new_list;
	int a = 1;
	int b = 2;
	int c = 3;

	list = ft_lstnew(&a);
	list->next = ft_lstnew(&b);
	list->next->next = ft_lstnew(&c);

	new_list = ft_lstmap(list, double_content, free_content);
	if (!new_list)
	{
		ft_lstclear(&list, free_content);
	}
	while (new_list)
	{
		printf("%d\n", *(int *)new_list->content);
		new_list = new_list->next;
	}
	printf("Complete!\n");
	system("leaks -q a.out");
}

int	main(int argc, char *argv[])
{
	char	*s = argv[argc - 1];
	printf("%s\n", s);
	printf("------ lstnew ------------------------\n");
	test_lstnew();
	printf("------ lstadd_front ------------------------\n");
	test_lstadd_front();
	printf("------ lstsize ------------------------\n");
	test_lstsize();
	printf("------ lstlast ------------------------\n");
	test_lstlast();
	printf("------ lstadd_back ------------------------\n");
	test_lstadd_back();
	printf("------ lstdelone ------------------------\n");
	test_lstdelone();
	printf("------ lstclear ------------------------\n");
	test_lstclear();
	printf("------ lstiter ------------------------\n");
	test_lstiter();
	printf("------ lstmap ------------------------\n");
	test_lstmap();
	return (0);
}
