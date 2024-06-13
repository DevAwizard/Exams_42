#include <unistd.h>


/* 
Examples:

Example 1:
   Input: value = 5
   Binary Representation: 00000101
   Expected Output: 00000101

Example 2:
   Input: value = 255
   Binary Representation: 11111111
   Expected Output: 11111111

Example 3:
   Input: value = 128
   Binary Representation: 10000000
   Expected Output: 10000000

Example 4:
   Input: value = 0
   Binary Representation: 00000000
   Expected Output: 00000000 
*/

// Function that prints the bits of a byte (unsigned char) in order
void print_bits(unsigned char octet)
{
    int index;
    
    unsigned char bit;

    // Initialize index to 8 because there are 8 bits in a byte
    index = 8;
    // While index decrements (the goal is to reach 0 because this indicates that all bits have been processed)
    while (index--)
    {
        // Assign the value of the current bit and convert it to the character '0' or '1'
        bit = ((octet >> index) & 1) + '0';

        // Print the current bit
        write(1, &bit, 1);
    }
}

// Main function

int main()
{
    unsigned char value = 5; // Binary: 00000101
    print_bits(value); // Expected output: 00000101
    write(1, "\n", 1); // Newline for clarity

    value = 255; // Binary: 11111111
    print_bits(value); // Expected output: 11111111
    write(1, "\n", 1); // Newline for clarity

    value = 128; // Binary: 10000000
    print_bits(value); // Expected output: 10000000
    write(1, "\n", 1); // Newline for clarity

    value = 0; // Binary: 00000000
    print_bits(value); // Expected output: 00000000
    write(1, "\n", 1); // Newline for clarity

    return 0;
}
