#include "list.h"

/* The goal is to sort a linked list of nodes according to a comparison criterion defined by a comparison function passed as a parameter.
In this case, the comparison function returns 0 if two elements need to be swapped.

Example

Original list:
3 1 4 2 
Sorted list:
3 4 2 1  */

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    // Variable declaration
	
    // Variable to indicate if swaps were made in a pass
    int swapped;

    // Pointer to traverse the list
    t_list *current;
	
    // Pointer to mark the boundary of the unsorted part of the list
    t_list *last_ptr = NULL;

    // If lst is NULL, return NULL
    if (lst == NULL)
        return (NULL);

    // Main loop to traverse the list
    while (1)
    {
        // Reset the swap indicator at the beginning of each pass
        swapped = 0;

        // Start from the beginning of the list
        current = lst;
		
        // Inner loop to traverse the list up to last_ptr
        while (current->next != last_ptr)
        {
            // If the elements are in the wrong order according to cmp, swap them
            if ((*cmp)(current->data, current->next->data) == 0)
            {
                // Swap the data of the current nodes
                int temp_data = current->data;
                current->data = current->next->data;
                current->next->data = temp_data;
                // Indicate that a swap was made
                swapped = 1;
            }
            // Move to the next node
            current = current->next;
        }
        // Update last_ptr to reduce the unsorted part of the list
        last_ptr = current;

        // If no swaps were made, the list is sorted
        if (swapped == 0)
            // Exit the main loop
            break;
    }

    // Return the pointer to the beginning of the sorted list
    return (lst);
}
