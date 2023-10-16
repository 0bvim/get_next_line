/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/28 04:58:29 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file_info	file;

	if ((!fd || fd < 0) && fd != 0)
		return (NULL);
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
		if (file.read == -1)
			return (free_str(file.string));
	}
	if (file.read <= 0 || file.buffer[file.pos] == '\0')
	{
		if (file.read < 0 && file.string)
			free_str(file.string);
		return (NULL);
	}
	return (ft_read_line(&file));
}

char	*ft_read_line(t_file_info *file)
{
	file->len = 0;
	while (file->read > 0)
	{
		link_letter(&file->string, get_letter(*(file->buffer + file->pos)));
		if (*(file->buffer + file->pos) == '\n'
			|| *(file->buffer + file->pos) == '\0')
			break ;
		file->pos++;
		file->len++;
		if (file->pos >= file->read)
		{
			file->pos = 0;
			file->read = read (file->fd, file->buffer, BUFFER_SIZE);
			if (file->read == -1)
				return (free_str(file->string));
		}
	}
	file->pos++;
	file->len++;
	return (ft_build_line(file));
}

char	*ft_build_line(t_file_info *file)
{
	t_char	*next;
	char	*line;
	int		count;

	line = (char *)malloc((file->len + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	count = 0;
	next = NULL;
	while (file->string)
	{
		next = file->string->next;
		line[count] = file->string->single_char;
		free(file->string);
		file->string = next;
		count++;
	}
	line[count] = '\0';
	return (line);
}
