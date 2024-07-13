#include "list.h"

/* The goal is to sort a linked list of nodes according to a comparison criterion defined by a comparison function passed as a parameter.
In this case, the comparison function returns 0 if two elements need to be swapped.

Example

Original list:
3 1 4 2 
Sorted list:
3 4 2 1  */

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int swap;
	t_list *temp;
	t_list *start;

	start = lst;
	while (lst != NULL)
	{
		temp = start;
		while (temp->next != NULL)
		{
			if (((cmp)(temp->data, temp->next->data)) > 0)
			{
				swap = temp->data;
				temp->data = temp->next->data;
				temp->next->data = swap;
			}
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (start);
}

int ascending(int a, int b)
{
    return (a - b);
}



// Function to create a new node
t_list *create_node(int data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the list
void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    // Create an unsorted linked list
    t_list *list = create_node(4);
    list->next = create_node(3);
    list->next->next = create_node(5);
    list->next->next->next = create_node(8);

    // Print the original list
    printf("Lista original:\n");
    print_list(list);

    // Sort the list
    list = sort_list(list, ascending);

    // Print the sorted list
    printf("Lista ordenada:\n");
    print_list(list);

    // Free memory
    t_list *temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
