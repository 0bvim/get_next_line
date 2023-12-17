#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>


int main()
{
    char *name = "test.txt";
    char *name1 = "test1.txt";

    int fd = open(name, O_RDONLY);
    int fd1 = open(name1, O_RDONLY);
    char *t = NULL;
    char *t1 = NULL;
	while ((t = get_next_line(fd)) || (t1 = get_next_line(fd1)))
	{
		printf("%s", t);
		free(t);
		printf("%s", t1);
		free(t1);
	}
    close(fd);
    close(fd1);
	return (EXIT_SUCCESS);
}

