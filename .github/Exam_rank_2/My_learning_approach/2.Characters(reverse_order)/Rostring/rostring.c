#include <unistd.h>

void	first_word(char *string)
{
	int	index;
	
	index = 0;
	while (string[index] != '\0' && (string[index] == ' ' || string[index] == '\t'))
		index++;
	while(string[index] != '\0' && string[index] != ' ' && string[index] != '\t')
	{
		write(1,&string[index],1);
		index++;
	}
}

int	main(int argc, char **argv)
{
	int index;
	char	*string;

	index = 0;
	string = argv[1];
	if (argc >= 2)
	{
		while (string[index] != 0 && (string[index] == ' ' || string[index] == '\t'))
			index++;
		while (string[index] != 0 && string[index] != ' ' && string[index] != '\t')
			index++;
		while (string[index] != 0)
		{
			if (string[index] != ' ' && string[index] != '\t')
			{
				write (1,&string[index], 1);
				if (string[index + 1] == ' ' || string[index + 1] == '\t' || string[index + 1] == '\0')
					write(1," ",1);
			}
			index++;
		}
		first_word(string);
	}
	write(1,"\n",1);
	return (0);
}
