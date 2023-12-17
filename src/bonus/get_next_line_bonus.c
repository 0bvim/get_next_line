/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/17 11:57:29 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl[1024];

	if (gnl[fd].pos >= gnl[fd].read || gnl[fd].pos == IN)
	{
		gnl[fd] = init_gnl(&gnl[fd], fd);
		if (gnl[fd].read == -1 || gnl[fd].read < 0 || gnl[fd].buffer[gnl[fd].pos] == '\0')
		{
			if (gnl[fd].list)
				return (free_str(gnl[fd].list));
			return (NULL);
		}
	}
	return (ft_read_line(&gnl[fd]));
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
