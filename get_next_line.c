/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/17 22:52:10 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_char	*x;
}

int	main()
{
	char *buf = (char *)calloc(100,sizeof(char));
	size_t size = 10;
	int	fd = open("a", O_RDONLY);

	size_t rde = read (fd, buf, size);
	printf("%d\n", fd);
	printf("%zu\n", rde);
	close (fd);
	return (0);
}

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

