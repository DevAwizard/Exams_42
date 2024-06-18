#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index_argv;
	int index_char;
	
	index_argv = 1;
	index_char = 0;
	char	last_letter;
	
	if (argc > 1)
	{
		while (argv[index_argv] != 0)
		{
			index_char = 0;
			while (argv[index_argv][index_char] != '\0')
			{
				if (argv[index_argv][index_char] >= 'a' && argv[index_argv][index_char] <= 'z' && (argv[index_argv][index_char+1] == ' ' || argv[index_argv][index_char+1] == '\t' || argv[index_argv][index_char+1] == '\0'))
				{
					last_letter = argv[index_argv][index_char] - 32;
					write(1,&last_letter,1);
				}
				else if (argv[index_argv][index_char] >= 'A' && argv[index_argv][index_char] <= 'Z' && (argv[index_argv][index_char+1] != ' ' && argv[index_argv][index_char+1] != '\t' && argv[index_argv][index_char+1] != '\0'))
				{
					last_letter = argv[index_argv][index_char] + 32;
					write(1,&last_letter,1);
				}
				else
					write(1,&argv[index_argv][index_char],1);
				index_char++;
			}
			write(1,"\n",1);
			index_argv++;
		}
	}
	else
		write(1,"\n",1);
	return (0);
}


