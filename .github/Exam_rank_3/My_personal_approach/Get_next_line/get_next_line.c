#include "get_next_line.h"

char *ft_strdup(char *string)
{
	int index;
	char *dup;
	
	index = 0;

	while (string[index])
		index++;
	
	dup = malloc((index + 1) *sizeof(char));

	if (!dup)
		return (NULL);

	index = 0;
	while (string[index])
	{
		dup[index] = string[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}


char *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static int		buffer_index = 0;
	static int		buffer_readed = 0;
	char			line[70000];
	int				index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	while (1)
	{
		if (buffer_index >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[index++] = buffer[buffer_index++];
		if (line[index - 1] == '\n')
			break ;
	}
	line[index] = '\0';
	if (index == 0)
		return (NULL);
	return (ft_strdup(line));
}

int main (void)
{
	int		fd;
	char	*line;

	fd = open ("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("cant be opened\n"), 1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("\n");
	close(fd);
	return (0);
}
