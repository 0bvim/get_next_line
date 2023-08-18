/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/18 03:14:31 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_file_info	file;

	if (file.pos >= file.read || file.pos == 0)
	{
		file.pos = 0;
		while (file.pos < BUFFER_SIZE)
			file.buffer[file.pos++] = '\0';
		file.pos = 0;
		file.string = NULL;
		file.len = 0;
		file.fd = fd;
		file.read = read(fd, file.buffer, BUFFER_SIZE);
	}
	return (file.buffer);
}

int	main(void)
{
	char *buf = (char *)calloc(100,sizeof(char));
	size_t size = 10;
	int	fd = open("a", O_RDONLY);
	ssize_t read1 = read (fd, buf, size);

	printf("%d\n", fd);
	printf("%ld\n", read1);
	printf("%s\n", get_next_line(fd));
	close (fd);
	return (0);
}

