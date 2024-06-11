int ft_size(char *string)
{
	int index;
	
	index = 0;

	while (string[index] != '\0')
		index++;
	return (index);
}