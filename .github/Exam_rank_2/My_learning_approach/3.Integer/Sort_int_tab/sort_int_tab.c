
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


void print_array(int *array, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr1[] = {5, 3, 8, 4, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    // Sort and print the first array
    sort_array(arr1, size1);
    printf("Sorted array1: ");
    print_array(arr1, size1);

    int arr2[] = {10, -2, 33, 5, 1, 0};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Sort and print the second array
    sort_array(arr2, size2);
    printf("Sorted array2: ");
    print_array(arr2, size2);

    int arr3[] = {100, 50, 25, 75, 0, -50};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    // Sort and print the third array
    sort_array(arr3, size3);
    printf("Sorted array3: ");
    print_array(arr3, size3);

    return 0;
}