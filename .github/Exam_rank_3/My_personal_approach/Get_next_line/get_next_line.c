#include "get_next_line.h"

char *ft_strdup(char *string)
{
	int index;
	char *duplicate;
	
	index = 0;
	while (string[index])
		index++;
	duplicate = malloc((index + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	index = 0;
	while(string[index])
	{
		duplicate[index] = string[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index = 0;
	static int buffer_readed = 0; // es un int no un char 
	int index;
	char line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 0;
	while (1)
	{
		if (buffer_index >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (buffer_readed <= 0) // Acordarse de esto
				break ;
		}
		line[index++] = buffer[buffer_index++];

		if (line[index - 1] == '\n' || line[index - 1] == EOF)
			break ;
	}
	if (index == 0) // acordarse que es index 
		return (NULL);
	line[index] = '\0';
	return (ft_strdup(line));
}

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Fd cant be openned\n"), 1);

	while ((line = get_next_line(fd))) // acordarme que son 3 parentesis
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
