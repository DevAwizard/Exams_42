#include "flood_fill.h"

// Recursive helper function to perform the flood fill algorithm
void flood_fill_helper(char **tab, t_point init, t_point size, char c)
{
    // Ensure we do not go out of the square, if we do, return
    if (init.y >= size.y || init.x >= size.x || init.x < 0 || init.y < 0)
        return;
    
    // If the current character is not the original character, return
    else if (tab[init.y][init.x] != c)
        return;
    
    // Mark the current point with 'F'
    tab[init.y][init.x] = 'F';

    // Recursively call 4 times for up, down, left, and right
    flood_fill_helper(tab, (t_point){init.x - 1, init.y}, size, c); // Left
    flood_fill_helper(tab, (t_point){init.x, init.y - 1}, size, c); // Up
    flood_fill_helper(tab, (t_point){init.x + 1, init.y}, size, c); // Right
    flood_fill_helper(tab, (t_point){init.x, init.y + 1}, size, c); // Down
}

// Main function to initiate the flood fill algorithm
void flood_fill (char **tab, t_point size, t_point begin)
{   
    // Get the initial character from the starting point
    char c = tab[begin.y][begin.x];
    // Call the flood_fill_helper function with the initial parameters
    flood_fill_helper(tab, begin, size, c);
}

// Provided (make area and main program)

char** make_area(char** zone, t_point size)
{
    char** new;

    new = malloc(sizeof(char*) * size.y);
    for (int i = 0; i < size.y; ++i)
    {
        new[i] = malloc(size.x + 1);
        for (int j = 0; j < size.x; ++j)
            new[i][j] = zone[i][j];
        new[i][size.x] = '\0';
    }

    return new;
}

int main(void)
{
    t_point size = {8, 5};  // Define the size of the grid
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
    };

    // Create a copy of the grid
    char** area = make_area(zone, size);

    // Print the original grid
    printf("Original grid:\n");
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);
    printf("\n");

    t_point begin = {7, 4};  // Define the starting point for flood fill

    // Perform the flood fill
    flood_fill(area, size, begin);

    // Print the filled grid
    printf("Filled grid:\n");
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);

    // Free the allocated memory
    for (int i = 0; i < size.y; ++i)
        free(area[i]);
    free(area);

    return 0;
}