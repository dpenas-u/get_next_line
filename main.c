#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	fd;
	char	buffer[BUFFER_SIZE + 1];
	int	ret;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buffer, BUFFER_SIZE);
		printf("ret: %d\n", ret);
		buffer[ret] = 0;
		printf("buffer: %s\n", buffer);
		close(fd);
	}
}
