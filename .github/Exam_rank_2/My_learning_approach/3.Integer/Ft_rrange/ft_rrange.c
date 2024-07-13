#include <stdlib.h> // Malloc & NULL
#include <stdio.h> // Printf
#include <math.h> // abs

/*
Example:
Input: start = 1, end = 3
Output: [3, 2, 1]

Input: start = -1, end = 2
Output: [2, 1, 0, -1]

Input: start = 0, end = 0
Output: [0]

Input: start = 3, end = -3
Output: [-3, -2, -1, 0, 1, 2, 3]
*/

/int *ft_rrange(int start, int end)
{
    int     *rrange;
    int     index;
    long    len;
    index = 0;
	
	if (start == end)
		len = 1;
    
	if (start > end)
        len = (long)start - (long)end + 1;
    
	if (end > start)
        len = (long)end - (long)start + 1;
    rrange = (int *)malloc(sizeof(int) * len);
    
	if (!rrange)
        return (NULL);
   
    if (start == end)
        rrange[index] = end;
    else
    {
        while (index < len)
        {
            if (end > start)
                rrange[index++] = end--;
            else
                rrange[index++] = end++;
        }
    }
    return (rrange);
}

// Main program

int main()
{
    int *range;
    int i, length;

    // Test 1: Start at INT_MIN and end at INT_MIN + 5
    int start = INT_MIN;
    int end = INT_MIN + 5;
    range = ft_rrange(start, end);
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
    range = ft_rrange(start, end);
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
    range = ft_rrange(start, end);
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
