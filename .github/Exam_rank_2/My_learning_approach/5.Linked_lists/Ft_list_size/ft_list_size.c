#include "ft_list.h"


// Function to calculate the number of elements in a linked list
int ft_list_size(t_list *begin_list)
{
    int size;

    size = 0;

    while (begin_list)
    {
        begin_list = begin_list->next;

        size++;
    }

    return size;
}

