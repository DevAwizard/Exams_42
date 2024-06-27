#include "ft_list.h"
#include <string.h> // For strcmp and strdup

/*
Usage example:
Suppose we have a linked list with the following values: 1 -> 2 -> 3 -> 4 -> 5 and we want to remove all nodes whose value is 3.

t_list *node1 = ...;  // node1 -> node2 -> node3 -> node4 -> node5 -> NULL
t_list *node2 = ...;
t_list *node3 = ...;
t_list *node4 = ...;
t_list *node5 = ...;

node1->next = node2;
node2->next = node3;
node3->next = node4;
node4->next = node5;
node5->next = NULL;

void *data_ref = ...; // data_ref contains the value 3
int cmp(void *data1, void *data2) { return (*(int*)data1 - *(int*)data2); }

ft_list_remove_if(&node1, data_ref, cmp);

Program/function description:
This function takes as input a pointer to the pointer of the first node of a linked list (`begin_list`), a pointer to the reference data (`data_ref`), and a pointer to a comparison function (`cmp`). The `cmp` function takes two data pointers and returns 0 if the data are equal, and a non-zero value if they are different.

The `ft_list_remove_if` function traverses the linked list and removes all nodes whose data match `data_ref`. It uses recursion to advance through the list and remove the necessary nodes.

1. If the list is empty or the pointer to the start of the list is NULL, the function returns without doing anything.
2. If the current node should be removed (according to the comparison function), it saves the node in `temp`, advances the pointer to the next node, frees the current node, and recursively calls `ft_list_remove_if`.
3. If the current node should not be removed, it recursively calls `ft_list_remove_if` with the next node.
*/

// Function to remove all nodes from a linked list whose data matches data_ref, using a comparison function

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    // Declare variable, which is a temporary pointer to store the node to be removed
    t_list *temp;

    // Check if the list is empty or if the pointer to the start of the list is NULL
    if (begin_list == NULL || *begin_list == NULL)
        return;

    // Check if the current node should be removed
    if (cmp((*begin_list)->data, data_ref) == 0)
    {
        // Save the current node in temp
        temp = *begin_list;
        
        // Advance the pointer to the next node
        *begin_list = (*begin_list)->next;
        
        // Free the current node
        free(temp);
       
        // Recursively call ft_list_remove_if to process the next node
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        // If the current node should not be removed, recursively call with the next node
        ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
    }
}
