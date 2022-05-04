#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * - create : rd (return of read), c (char to be stored), i (iterator), buff (malloced to 9999).
 * - loop read(fd, &c, 1) until it rd <= 0
 *   	- put c inside buff[i].
 *   	- increment i.
 *   	- if (c = '\n') break the loop.
 * - if (rd < 0 or rd = 0), free buff and return 0.
 * - add '\0' to the end of buff
 * - return buff.
*/


int	get_next_line_int(int fd)
{
	int	rd;
	int	i = 0;
	char	c;
	char	*buffer = malloc(9999);

	while ((rd = read(fd, &c, 1) > 0))
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (!rd || rd == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[++i] = '\0';
	return (i);
}


char	*get_next_line_char(int fd)
{
	int	rd;
	int	i = 0;
	char	c;
	char	*buffer = malloc(9999);

	while ((rd = read(fd, &c, 1) > 0))
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (!rd || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

int	main(void)
{
	int fd;
	int ret;
	char *line;

	fd = open("./text.txt", O_RDONLY);
	if (fd < 0)
		return (0);

	while (ret = get_next_line_int(fd))
		printf("%d\n", ret);

//	while (line = get_next_line_char(fd))
//		printf("%s", line);
}
