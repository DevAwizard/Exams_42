# include <stdio.h>

/*
Example:
Input: 5, 3, 8, 4, 2
Output: Sorted array: 2 3 4 5 8

Input: 10, -2, 33, 5, 1, 0
Output: Sorted array: -2 0 1 5 10 33

Input: 100, 50, 25, 75, 0, -50
Output: Sorted array: -50 0 25 50 75 100
*/

// Sort the numbers in an integer array in ascending order

void sort_int_tab (int *tab, unsigned int size)
{
	unsigned int current_index;
	int temporal_variable;

	current_index = 0;

	while(current_index < (size - 1))
	{
		if (tab[current_index] > tab[current_index + 1])
		{
			temporal_variable = tab[current_index];
			tab[current_index] = tab[current_index + 1];
			tab[current_index + 1] = temporal_variable;

			current_index = 0;
		}
		else
			current_index++;
	}
}

// Main program

int main()
{
    int array[] = {5, 3, 8, 1, 2, 7, 4, 6};
    unsigned int size = sizeof(array) / sizeof(array[0]);
    unsigned int i = 0;

    printf("Array before sorting:\n");
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    sort_int_tab(array, size);

    i = 0;

    printf("Array after sorting:\n");
    
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    return 0;
}
