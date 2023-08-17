/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:23:40 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/16 19:44:39 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# endif

// buffer to read
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

// libs
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// struct to be the static var
typedef struct s_char	t_char;
struct s_char
{
	char	single_fckr;
	t_char	*next;
};

// function
char	*get_next_line(int fd);

t_char	*char_push(char sf)
{
	t_char	*new_fckr;

	new_fckr = (t_char *)malloc(sizeof(t_char));

	if (!new_fckr)
		return (NULL);
	new_fckr->single_fckr = sf;
	new_fckr->next = NULL;

	return (new_fckr);
}

void	char_next_last(t_char **head, t_char *set)
{
	t_char	*upd;

	if (!set)
		return ;
	if (!*head)
	{
		*head = set;
		return ;
	}
	upd = *head;
	while (upd->next)
		upd = upd->next;
	upd->next = set;
}
