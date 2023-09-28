#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	main()
{
	char	*file = "noperm";
	char	*result = malloc(sizeof(char) * 5);
	int	fdo = open(file, O_RDONLY);
	int	fd = read(fdo, result, 10);
	
	
	printf("\n%d\n", fdo);
	printf("\n%d\n", fd);
	printf("\n%s\n", result);
	close(fdo);
}
