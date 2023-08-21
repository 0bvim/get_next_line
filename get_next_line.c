/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/20 22:43:19 by vde-frei         ###   ########.fr       */
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
	if (file.read <= 0 || file.buffer[file.pos] == '\0')
		return (NULL);
	return (ft_read_line(&file));
}

static char	*ft_read_line(t_file_info *info)
{
	info->len = 0;
	while (TRUE)
	{
		link_letter(&info->str, get_letter(*(info->buffer + info->pos)));
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*retrn;

	fd = open(argv[1], O_RDONLY);
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
