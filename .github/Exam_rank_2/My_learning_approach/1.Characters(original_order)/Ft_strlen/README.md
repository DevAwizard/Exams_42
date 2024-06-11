# Ft_strlen

```sh
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:


int	ft_strlen(char *str);


### Solution
// Function to calculate the length of a string
int ft_strlen(char *str)
{
  int index; // Variable to store the index of the current character

  index = 0; // Initialize index to 0
  // Loop until the null terminator '\0' is encountered
  while (str[index] != '\0')
    index++; // Increment index to move to the next character in the string
  return (index); // Return the length of the string
}
```