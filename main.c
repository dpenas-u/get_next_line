#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	fd;
	char	buf;
	int	ret;
	char	*buffer;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while(read(fd, &buf, 1) && buf != 10)
			printf("%c", buf);
		printf("\n");
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ret = read(fd, buffer, BUFFER_SIZE);
		printf("ret: %d\n", ret);
		buffer[ret] = 0;
		printf("buffer: %s\n", buffer);
		close(fd);
	}
	system("leaks a.out");
}
