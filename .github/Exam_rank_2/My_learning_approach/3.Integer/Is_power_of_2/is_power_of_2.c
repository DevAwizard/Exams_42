# include <stdio.h>

// Function that checks if a number is a power of 2. 
// It returns true(1) if the number is a power of 2, and false(0) otherwise.

/* 
Example

is_power_of_2(0) = 0
is_power_of_2(1) = 1
is_power_of_2(2) = 1
is_power_of_2(3) = 0
is_power_of_2(4) = 1
is_power_of_2(8) = 1
is_power_of_2(10) = 0
is_power_of_2(16) = 1
is_power_of_2(18) = 0
is_power_of_2(32) = 1
is_power_of_2(64) = 1
is_power_of_2(100) = 0 
*/

// Function that checks if a number is a power of 2
int is_power_of_2(unsigned int number)
{
	if (number == 0)
		return (0);
	
	while (number % 2 == 0) 
		number = number / 2;

	if (number == 1)
		return (1);
	else
		return (0);
}

// Main program

int main(void)
{
    unsigned int test_numbers[] = {0, 1, 2, 3, 4, 8, 10, 16, 18, 32, 64, 100};
    int num_tests;
    int index;
    unsigned int number;

    num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);
    index = 0;

    while (index < num_tests)
    {
        number = test_numbers[index];
        printf("is_power_of_2(%u) = %d\n", number, is_power_of_2(number));
        index++;
    }

    return 0;
}