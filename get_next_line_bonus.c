/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:06:06 by cw3l              #+#    #+#             */
/*   Updated: 2024/11/09 20:14:29 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_traitement(int fd, char *buff, char *line, char **stach);

char	*clean(char **old_ptr, char *new)
{
	free (*old_ptr);
	*old_ptr = new;
	return (*old_ptr);
}

char	*ft_process(int fd, char *buff, char *line, char **stach)
{
	line = clean(&line, ft_strjoin(line, buff));
	if (!line)
		return (NULL);
	if (ft_len_index_of(buff, 'l') > 0)
		line = read_traitement(fd, buff, line, stach);
	return (line);
}

char	*read_traitement(int fd, char *buff, char *line, char **stach)
{
	char	*t;
	char	*tmp;
	int		b;
	int		index_return;

	b = read(fd, buff, BUFFER_SIZE);
	if (b < 0)
	{
		free(line);
		return (NULL);
	}
	buff[b] = '\0';
	if (b == 0)
		return (line);
	index_return = ft_len_index_of(buff, 'i');
	if (index_return == -1)
		return (ft_process(fd, buff, line, stach));
	tmp = ft_substr(buff, 0, index_return + 1);
	line = clean(&line, ft_strjoin(line, tmp));
	free(tmp);
	t = ft_strchr(buff, 10) + 1;
	*stach = ft_strdup(t);
	return (line);
}

char	*ft_stach_processing(char **stach, char **line, char **buffer)
{
	char	*tmp1;
	char	*tmp2;
	int		index_return;
	int		len_return;

	index_return = ft_len_index_of(*stach, 'i') + 1;
	len_return = ft_len_index_of(*stach, 'l');
	tmp1 = ft_substr(*stach, 0, index_return);
	*line = ft_strjoin(*line, tmp1);
	if (!(*line))
		return (NULL);
	free(tmp1);
	tmp2 = ft_substr(*stach, index_return, len_return - index_return);
	free(*stach);
	if (ft_len_index_of(tmp2, 'l') == 0)
	{
		free(tmp2);
		*stach = NULL;
	}
	else
		*stach = tmp2;
	free(*buffer);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stach[200];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = NULL;
	if (stach[fd] && ft_len_index_of(stach[fd], 'i') > -1)
		return (ft_stach_processing(&stach[fd], &line, &buffer));
	else
	{
		line = clean(&line, ft_strjoin(line, stach[fd]));
		free(stach[fd]);
		stach[fd] = NULL;
	}
	line = read_traitement(fd, buffer, line, &stach[fd]);
	free(buffer);
	return (line);
}
// #include <stdio.h>

// int main(void)
// {
// 	int fd1;
// 	int fd2;

// 	fd1 = open("file1.txt",O_RDONLY);
// 	if(fd1 == -1)
// 	{
// 		printf("erreur\n");
// 		return (-1);
// 	}
// 	fd2 = open("file2.txt",O_RDONLY);
// 	if(fd2 == -1)
// 	{
// 		printf("erreur\n");
// 		return (-1);
// 	}
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// 	printf("%s\n", get_next_line(fd1));
	
// 	return(0);
// }