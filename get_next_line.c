/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/16 22:18:59 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
}

int	main()
{
	char *buf = (char *)calloc(100,sizeof(char));
	size_t size = 10;
	int	fd = open("a", O_RDONLY);

	size_t rde = read (fd, buf, size);
	printf("%d\n", fd);
	printf("%d\n", rde);
	close (fd);
	return (0);
}
