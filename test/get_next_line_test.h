/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:52:16 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/11/09 20:21:27 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_LIMITS 200

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <libc.h>
# include <assert.h>
# include <unistd.h>

char	*clean(char **old_ptr, char *new);


int		ft_strlen_idx(const char *s, int mode);

char	*ft_substr(char *str, int start, int len);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);

/**
 * @brief Mixe d'une fonction indexof et strlen.
 * 
 * Instructions :
 * - Passe deux entiers en paramètre.
 * - La fonction retourne leur somme.
 * 
 * @param s La string a analyser
 * @param mode 'i' for index of line return, 'l' for len
 * @return La longueur ou l'index
 */
int		ft_len_index_of(char *str, char mode);
char	*ft_stach_processing(char **stach, char **line);

#endif