#include "get_next_line.h"

char *taitement(int fd, char *buff, char *line, char **stach, int b);

char *ft_process(int fd, char *buff, char *line, char **stach, int b)
{
	line = clean(&line,ft_strjoin(line, buff)); 
	if(!line)
		return (NULL);
	if (b > 0)
		line = taitement(fd, buff, line, stach, b);
	return (line);
}

char    *taitement(int fd, char *buff,char *line,char **stach, int b)
{
	char *t;

	b = read(fd,buff,BUFFER_SIZE);
	if(b < 0)
	{
		free(line);
		return (NULL);
	}
	buff[b] = '\0';
	if(b == 0)
		return(line);
	if(index__of(buff,10) == -1)
		return ft_process(fd,buff,line,stach,b);
	char *sub;

	sub = ft_substr(buff,0,index__of(buff,10) + 1);
	line = clean(&line ,ft_strjoin(line,sub));
	free(sub);
	t = ft_strchr(buff,10) + 1;
	*stach = ft_strdup(t);
	return(line);
}
char *get_next_line(int fd)
{
	int           b;
	char		*buffer;
	char		*line;
	static char	*stach[200];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	line = NULL;
	b = - 1;
	if (stach[fd] && index__of(stach[fd],10) > -1)
	{
		char *sub;
		sub = ft_substr(stach[fd],0,index__of(stach[fd],10) + 1);
		line = ft_strjoin(line,sub);
		free(sub);
		char *sub2 = ft_substr(stach[fd],index__of(stach[fd],10) + 1, ft_strlen(stach[fd]) - index__of(stach[fd],10) + 1 );
		free(stach[fd]);
		if(ft_strlen(sub2) == 0)
		{
			free(sub2);
			stach[fd] = NULL;
		}
		else
			stach[fd] = sub2;
		free(buffer);
		return(line);
	}
	else
	{
		line = clean(&line,ft_strjoin(line, stach[fd]));
		free(stach[fd]);
		stach[fd] = NULL;
	}
	line = taitement(fd, buffer,line, &stach[fd],b);
	if(!line)
		free(line);
	free(buffer);
	return(line);
}


// int main(void)
// {
// 	int fd;

// 	fd = open("file.txt",O_RDONLY);
// 	if(fd == -1)
// 	{
// 		printf("erreur\n");
// 		return (-1);
// 	}
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
	
	
	
   
// 	return(0);
// }