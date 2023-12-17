/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/17 03:43:00 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl;

	if (gnl.pos >= gnl.read || gnl.pos == IN)
	{
		gnl = init_gnl(&gnl, fd);
		if (gnl.read == -1 || gnl.read < 0 || gnl.buffer[gnl.pos] == '\0')
		{
			if (gnl.list)
				return (free_str(gnl.list));
			return (NULL);
		}
	}
	return (ft_read_line(&gnl));
}

char	*ft_read_line(t_gnl *gnl)
{
	gnl->len = 0;
	while (gnl->read > 0)
	{
		link_letter(&gnl->list, get_letter(gnl->buffer[gnl->pos]));
		if ((gnl->buffer[gnl->pos]) == '\n' || (gnl->buffer[gnl->pos]) == '\0')
			break ;
		gnl->pos++;
		gnl->len++;
		if (gnl->pos >= gnl->read)
		{
			gnl->pos = 0;
			gnl->read = read (gnl->fd, gnl->buffer, BUFFER_SIZE);
			if (gnl->read == FAIL)
				return (free_str(gnl->list));
		}
	}
	gnl->pos++;
	gnl->len++;
	return (ft_build_line(gnl));
}

char	*ft_build_line(t_gnl *gnl)
{
	t_char	*next;
	char	*line;
	int		count;

	line = malloc((gnl->len + CHAR) * CHAR);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	count = 0;
	next = NULL;
	while (gnl->list)
	{
		next = gnl->list->next;
		line[count] = gnl->list->single_char;
		free(gnl->list);
		gnl->list = next;
		count++;
	}
	line[count] = '\0';
	return (line);
}
