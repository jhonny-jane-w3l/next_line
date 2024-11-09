/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:52:16 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/11/09 13:21:57 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_LIMITS 200

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <assert.h>
# include <libc.h>

typedef struct s_get_next_line
{
    char            *line;
    char            *buffer;
    char            *stach;
    
}   t_get_next_line;

char	*clean(char **old_ptr, char *new);
int		ft_strlen_idx(const char *s, int mode);
char	*ft_substr(char *str, int start, int len);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_clean_process(char **buff, char **line, char **stach);

char    *ft_process_buffer(t_get_next_line *line, char *stach);
char	*ft_strchr(char *str, char c);


void *ft_clean_exit(t_get_next_line **process_b);
char	*ft_analyse(char *str);
int	index__of(char *str, char c);
int	ft_strlen(const char *s);
int	ft_len_index_of(char *str, char mode);

#endif