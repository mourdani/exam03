#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int i = 0;
	int rd;
	char *buff = malloc(9999);
	char c;

	while ((rd = read(fd, &c, 1)) > 0)
	{
		buff[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	if (!rd || rd == -1)
	{
		free(buff);
		return (NULL);
	}
	i++;
	buff[i] = '\0';
	return (buff);
}


int	main(void)
{
	int fd;
	int ret;
	char *line;

	fd = open("./text.txt", O_RDONLY);
	if (fd < 0)
		return (0);

//	while (ret = get_next_line_int(fd))
//		printf("%d\n", ret);

	while (line = get_next_line(fd))
		printf("%s", line);
}
