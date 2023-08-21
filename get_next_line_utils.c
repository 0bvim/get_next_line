/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:40:15 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/20 23:03:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = new_letter;
}
