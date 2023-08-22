/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/22 20:45:39 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file_info	file[1024];

	if ((!fd || fd > 1024 || fd < 0) && fd != 0)
		return (NULL);
	if (file[fd].pos >= file[fd].read || file[fd].pos == 0)
	{
		file[fd].pos = 0;
		while (file[fd].pos < BUFFER_SIZE)
			file[fd].buffer[file[fd].pos++] = '\0';
		file[fd].pos = 0;
		file[fd].string = NULL;
		file[fd].len = 0;
		file[fd].fd = fd;
		file[fd].read = read(fd, file[fd].buffer, BUFFER_SIZE);
		if (file[fd].read == -1)
			return (free_str(file[fd].string));
	}
	if (file[fd].read <= 0 || file[fd].buffer[file[fd].pos] == '\0')
	{
		free_str(file->string);
		return (NULL);
	}
	if (file[fd].read < 0 && file[fd].string)
		return (free_str(file->string));
	return (ft_read_line(&file[fd]));
}

char	*ft_read_line(t_file_info *info)
{
	info->len = 0;
	while (1)
	{
		link_letter(&info->string, get_letter(*(info->buffer + info->pos)));
		if (*(info->buffer + info->pos) == '\n'
			|| *(info->buffer + info->pos) == '\0')
			break ;
		info->pos++;
		info->len++;
		if (info->pos >= info->read)
		{
			info->pos = 0;
			info->read = read (info->fd, info->buffer, BUFFER_SIZE);
			if (info->read == -1)
				return (free_str(info->string));
			if (info->read <= 0)
				break ;
		}
	}
	info->pos++;
	info->len++;
	return (ft_build_line(info));
}

char	*ft_build_line(t_file_info *set)
{
	t_char	*next;
	char	*line;
	int		count;

	line = (char *)malloc((set->len + 1) * sizeof(char));
	if (!(line || set->fd) && set->fd != 0)
		return (NULL);
	count = 0;
	next = NULL;
	while (set->string)
	{
		next = set->string->next;
		line[count] = set->string->single_char;
		free(set->string);
		set->string = next;
		count++;
	}
	line[count] = '\0';
	return (line);
}
