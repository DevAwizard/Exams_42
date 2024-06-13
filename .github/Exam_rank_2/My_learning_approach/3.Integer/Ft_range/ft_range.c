
#include <stdlib.h> // Malloc & NULL
#include <stdio.h> // Printf
#include <math.h> // abs

// Function to create an array of integers from 'start' to 'end' (inclusive)

/*
Example:
Input: start = 5, end = 10
Output: [5, 6, 7, 8, 9, 10]

Input: start = 10, end = 5
Output: [10, 9, 8, 7, 6, 5]

Input: start = 7, end = 7
Output: [7]

Input: start = -5, end = 0
Output: [-5, -4, -3, -2, -1, 0]

Input: start = 0, end = -5
Output: [0, -1, -2, -3, -4, -5]
*/

// Function to create an array of integers from 'start' to 'end' (inclusive)
int *ft_range(int start, int end)
{
	int index;
	int size;
	int *array_integer;

	index = 0;
    
	// Calculo el tamaño del array basado en la diferencia entre start y end, más 1
	size = abs(start - end) + 1;

	array_integer = malloc(sizeof(int) * size);

	if (!array_integer)
		return (NULL);
	
	if (start > end)
	{
		while (index < size)
		{
			array_integer[index] = start;
			
			index++;
			start--;
		}
	}
	else if (start < end)
	{
		while(index < size)
		{
			array_integer[index] = start;

			index++;
			
			start++;
		}
	}
	else
	{
		array_integer[index] = start;
	}

	return (array_integer);
}

//  Main program

int main()
{
    int start, end, size;
    int *result;

    // Example 1
    start = 5;
    end = 10;
    size = abs(start - end) + 1;
    result = ft_range(start, end);
    print_array(result, size);
    free(result);

    // Example 2
    start = 10;
    end = 5;
    size = abs(start - end) + 1;
    result = ft_range(start, end);
    print_array(result, size);
    free(result);

    // Example 3
    start = 7;
    end = 7;
    size = abs(start - end) + 1;
    result = ft_range(start, end);
    print_array(result, size);
    free(result);

    // Example 4
    start = -5;
    end = 0;
    size = abs(start - end) + 1;
    result = ft_range(start, end);
    print_array(result, size);
    free(result);

    // Example 5
    start = 0;
    end = -5;
    size = abs(start - end) + 1;
    result = ft_range(start, end);
    print_array(result, size);
    free(result);

    return 0;
}