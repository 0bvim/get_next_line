/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:40:15 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/17 11:53:33 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_char	*get_letter(char letter)
{
	t_char	*set_char;

	set_char = (t_char *)malloc(sizeof(t_char));
	set_char->single_char = letter;
	set_char->next = NULL;
	return (set_char);
}

void	link_letter(t_char **head, t_char *new_letter)
{
	t_char	*aux;

	if (!new_letter)
		return ;
	if (!*head)
	{
		*head = new_letter;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = new_letter;
}

char	*free_str(t_char *string)
{
	t_char	*temp;

	temp = string;
	while (temp)
	{
		temp = temp->next;
		free(string);
		string = temp;
	}
	temp = NULL;
	return (NULL);
}

t_gnl	init_gnl(t_gnl *gnl, int fd)
{
	gnl->pos = 0;
	while (gnl->pos < BUFFER_SIZE)
		gnl->buffer[gnl->pos++] = '\0';
	gnl->pos = 0;
	gnl->list = NULL;
	gnl->len = 0;
	gnl->fd = fd;
	gnl->read = read(fd, gnl->buffer, BUFFER_SIZE);
	return (*gnl);
}
