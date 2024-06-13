# include <stdio.h>

/* Example

Array of integers -> 1, 3, 7, 0, 5, 9, 2

The maximum value in the array is: 9 

*/

// Function that finds and returns the maximum value in an array of integers

int max (int *tab, unsigned int len)
{
	int result;
	
	unsigned int index;

	if (len == 0)
		return (0);

	result = tab[0];

	index = 0;

	while (index < len)
	{
		if (result < tab[index])
			result = tab[index];
		
		index++;
	}
	return (result);
}


// Main program

#include <stdio.h>

int max(int *tab, unsigned int len);

int main() 
{
    int array[] = {3, 5, 7, 2, 8, 6, 4, 10};
    unsigned int len = sizeof(array) / sizeof(array[0]);
    
    int result = max(array, len);
    printf("The maximum value in the array is: %d\n", result);
    
    return 0;
}