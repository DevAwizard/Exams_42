
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

int *ft_range(int start, int end)
{
    int     *range;
    int     index;
    int    length;
    
	index = 0;
	length = 0;

    if (start == end)
       length = 1;
	
    if (start > end)
        length = (long)start - (long)end + 1;
    
    if (end > start)
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

// Main program

int main()
{
    int *range;
    int i, length;

    // Test 1: Start at INT_MIN and end at INT_MIN + 5
    int start = INT_MIN;
    int end = INT_MIN + 5;
    range = ft_range(start, end);
    if (range)
    {
        length = end - start + 1;
        printf("Range from %d to %d:\n", start, end);
        for (i = 0; i < length; i++)
        {
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range);
    }

    // Test 2: Start at INT_MAX - 5 and end at INT_MAX
    start = INT_MAX - 5;
    end = INT_MAX;
    range = ft_range(start, end);
    if (range)
    {
        length = end - start + 1;
        printf("Range from %d to %d:\n", start, end);
        for (i = 0; i < length; i++)
        {
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range);
    }

    // Test 3: Start at -5 and end at 5
    start = -5;
    end = 5;
    range = ft_range(start, end);
    if (range)
    {
        length = end - start + 1;
        printf("Range from %d to %d:\n", start, end);
        for (i = 0; i < length; i++)
        {
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range);
    }

    return 0;
}
