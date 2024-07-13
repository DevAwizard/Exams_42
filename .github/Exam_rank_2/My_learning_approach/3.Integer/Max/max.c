# include <stdio.h>

/* Example

Array of integers -> 1, 3, 7, 0, 5, 9, 2

The maximum value in the array is: 9 

*/

// Function that finds and returns the maximum value in an array of integers


int	max(int	*tab, unsigned int len)
{
	unsigned int	index;
	int max_number;

	index = 0;
	max_number = 0;
	if (tab == 0)
		return (0);
	
	
	if (len > 0)
	{
		max_number = tab[index];
		while (index < len)
		{
			if (max_number < tab[index])
				max_number = tab[index];
			index++;
		}
	}
	return (max_number);
}


// Main program

#include <stdio.h>


int main() 
{
    int array[] = {3, 5, 7, 2, 8, 6, 4, 10};
    unsigned int len = sizeof(array) / sizeof(array[0]);
    
    int result = max(array, len);
    printf("The maximum value in the array is: %d\n", result);
    
    return 0;
}
