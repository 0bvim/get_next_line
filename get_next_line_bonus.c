/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/21 16:28:23 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file_info	file[1024];

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
	}
	if (file[fd].read <= 0 || file[fd].buffer[file[fd].pos] == '\0')
		return (NULL);
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
	if (!line)
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
//int	main(int argc, char **argv)
//{
//	int		fd;
//	int		fd1;
//	int		fd2;
//	int		fd3;
//	char	*retrn;
//
//	fd = open(argv[1], O_RDONLY);
//	fd1 = open(argv[2], O_RDONLY);
//	fd2 = open(argv[3], O_RDONLY);
//	fd3 = open(argv[4], O_RDONLY);
//	(void)argc;
//	retrn = "";
//	while (retrn != NULL)
//	{
//		retrn = get_next_line(fd);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd1);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd2);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd3);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd1);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd2);
//		printf("%s", retrn);
//		free(retrn);
//		retrn = get_next_line(fd3);
//		printf("%s", retrn);
//		free(retrn);
//	}
//	close (fd);
//	return (0);
//}
//#include <string.h>
//int	main(int argc, char **argv)
//{
//	int		fd;
//	char	*retrn;
//	char	input[100];
//	char	*keyword = "exit\n";
//
//	fd = open(argv[1], O_RDONLY);
//	(void)argc;
//	while (retrn != null)
//	{
//		printf("ENTER -> Get next line or type exit to quit.\n");
//		fgets(input, sizeof(input), stdin);
//		if (strcmp(input, keyword) == 0)
//		{
//			printf("\nBye");
//			break ;
//		}
//		retrn = get_next_line(fd);
//		if (retrn != NULL)
//		{
//			printf("%s", retrn);
//			retrn = get_next_line(fd);
//		}
//		else
//		{
//			printf("\nCya");
//			break ;
//		}
//	}
//	close (fd);
//	return (0);
//}
