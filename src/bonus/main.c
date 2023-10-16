#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>


int main()
{
    char *name = "test.txt";

    int fd = open(name, O_RDONLY);
    char *t = NULL;
	
	while((t = get_next_line(fd)) != NULL)
	{
		printf("%s", t);
		free(t);
	}
	close(fd);
	return (0);
}
