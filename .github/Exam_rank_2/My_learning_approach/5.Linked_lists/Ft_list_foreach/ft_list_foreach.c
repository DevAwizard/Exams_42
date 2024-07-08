#include "ft_list.h"

/*
Usage example:
Suppose we have a linked list with the following values: "hello" -> "world" -> "!"

t_list *node1 = ...;  // node1 -> node2 -> node3 -> NULL
t_list *node2 = ...;
t_list *node3 = ...;

node1->next = node2;
node2->next = node3;
node3->next = NULL;

Function to print a string
void print_str(void *data) 
{
    printf("%s\n", (char *)data);
}

Apply the function print_str to each element of the list
ft_list_foreach(node1, print_str);

Program/function description:
This function takes as input a pointer to the first node of a linked list (`begin_list`) and a pointer to a function (`f`). The `ft_list_foreach` function traverses each node of the linked list and applies the function `f` to the data stored in each node.

1. Initializes a pointer `list_pointer` to the beginning of the list.
2. While `list_pointer` is not NULL, applies the function `f` to the data of the current node.
3. Advances to the next node of the list.
4. Continues until reaching the end of the list (when `list_pointer` is NULL).

Example input and output:
Input:
Linked list: "hello" -> "world" -> "."

Expected output:
hello
world
.
*/

// The function ft_list_foreach applies the function f to each element of the linked list.
// It receives a pointer to the start of the list (begin_list) and a pointer to the function f.

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

