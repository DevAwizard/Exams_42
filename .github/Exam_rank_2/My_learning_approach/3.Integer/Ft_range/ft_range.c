
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
    int     *range;
    int     index;
    int    length;
    
	index = 0;
	length = 0;
	if (start == end)
    {
        length = 1;
    }
    else if (start > end)
        length = (long)start - (long)end + 1;
    else if (end > start)
        length = (long)end - (long)start + 1;
    
	range = (int *)malloc(sizeof(int) * length);

    if (!range)
        return (NULL);
    
	if (start == end)
        range[index] = start;
    else
    {
        while (index < length)
        {
            if (start > end)
                range[index++] = start--;
            else
                range[index++] = start++;
        }
    }
    return (range);
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
