#include <unistd.h>
#include <stdio.h>

/*
Examples:

Example 1:
Input: 178 (Binary: 10110010)
Swapped Output: 10101011

Example 2:
Input: 4 (Binary: 00000100)
Swapped Output: 01000000

Example 3:
Input: 240 (Binary: 11110000)
Swapped Output: 00001111
*/

// Function that swaps the values of the two halves of a byte (unsigned char)
unsigned char swap_bits(unsigned char octet)
{
    // Swap the left 4 bits to the right and the right 4 bits to the left
    return ((octet >> 4) | (octet << 4));
}

// Function to print the bits of a byte (unsigned char)
void print_bits(unsigned char octet)
{
    int index;
    unsigned char bit;

    index = 8;
    while (index--)
    {
        bit = ((octet >> index) & 1) + '0';
        write(1, &bit, 1);
    }
}

int main()
{
    unsigned char value = 178; // Binary: 10110010
    unsigned char swapped = swap_bits(value);
    
    print_bits(value); // Expected output: 10110010
    printf("\n");
    print_bits(swapped); // Expected output: 10101011
    printf("\n");

    value = 4; // Binary: 00000100
    swapped = swap_bits(value);
    
    print_bits(value); // Expected output: 00000100
    printf("\n");
    print_bits(swapped); // Expected output: 01000000
    printf("\n");

    value = 240; // Binary: 11110000
    swapped = swap_bits(value);
    
    print_bits(value); // Expected output: 11110000
    printf("\n");
    print_bits(swapped); // Expected output: 00001111
    printf("\n");

    return 0;
}
