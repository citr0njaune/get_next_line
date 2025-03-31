#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*line;
	int i = 0;

	if (fd <= 2)
	{
		printf ("ERROR");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}