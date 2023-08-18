/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/18 16:30:36 by vde-frei         ###   ########.fr       */
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
//		file.string = NULL;
//		file.len = 0;
		file.fd = fd;
		file.read = read(fd, file.buffer, BUFFER_SIZE);
	}
	if (file.read <= 0 || file.buffer[file.pos] == '\0')
		return (NULL);
	return (file.buffer);
}

int	main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	char	*retrn;

	(void)argc;
	retrn = "";
	while (retrn != NULL)
	{
		retrn = get_next_line(fd);
		printf("%s", retrn);
	}
	close (fd);
	return (0);
}

