#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	fd;
	char	*s;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		/*
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		*/
		///*
		while ((s = get_next_line(fd)))
		{
			printf("%s", s);
			//printf("\n----\n");
			free(s);
		}
		//*/
		close(fd);
	}
	system("leaks a.out");
}
