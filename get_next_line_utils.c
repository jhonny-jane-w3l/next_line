/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:52:55 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/11/09 11:41:24 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
        i++;
    return (i);
}

int	index__of(char *str, char c)
{
	int i;
	
	i = 0;
	if (!str)
		return (-1);
	while (str && str[i])
	{
		if(str[i] == c)
			return (i);
		i++;
	}
	return(-1);
}

char	*clean(char **old_ptr, char *new)
{
	//printf("voici old pointer %p\n",*old_ptr);
	free (*old_ptr);
	*old_ptr = new;
	//printf("voici new pointer %p\n",*old_ptr);
	return (*old_ptr);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*sub;
	int		str_len;
	int		i;

	if (!str)
		return (NULL);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	str_len = ft_strlen(str);
	i = 0;
	if (start > str_len)
		return ("");
	while (str[start] && i < len)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	if (len == 0)
		return (NULL);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*new_str;
	char 	*tmp;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len + 1));
	tmp = s1;
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp && tmp[j])
		new_str[i++] = tmp[j++];
	j = 0;
	tmp = s2;
	while (tmp && tmp[j])
		new_str[i++] = tmp[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(char *str, char c)
{
	if(!str)
		return(NULL);
	while (*str)
	{
		if(*str == c)
			return(str);
		str++;
	}
	return (NULL);

}

// char	*ft_strjoin(char **s1, char **s2)
// {
// 	int		len;
// 	int		i;
// 	int		j;
// 	char	*new_str;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	len = ft_strlen_idx(s1, 1) + ft_strlen_idx(s2, 1);
// 	new_str = malloc(sizeof(char) * (len + 1));
// 	if (!new_str)
// 		return (ft_clean_alloc(s1));
// 	i = 0;
// 	j = 0;
// 	while (s1 && s1[j])
// 		new_str[i++] = s1[j++];
// 	j = 0;
// 	while (s2 && s2[j])
// 		new_str[i++] = s2[j++];
// 	new_str[i] = '\0';
// 	return (new_str);
// }


// int main()
// {
// 	// assert(ft_strlen_idx("hello", 1) == 5 );
// 	// assert(ft_strlen_idx("", 1) == 0);
// 	// assert(ft_strlen_idx("hello", 2) == -1 );
// 	// assert(ft_strlen_idx("hello\nworld", 2) == 6 );
// 	// assert(ft_strlen_idx("\n", 2) == 1 );
// 	// assert(ft_strlen_idx("hello\n", 2) == 6 );
// 	// assert(ft_strlen_idx(NULL, 2) == 0 );
// 	// assert(ft_strlen_idx(NULL, 1) == 0 );
// 	// assert(!strcmp(ft_substr("hello world",6,5),"world"));
// 	// int len = ft_strlen_idx("hello\nworld",1);
// 	// int idx = ft_strlen_idx("hello\nworld",2);
// 	// assert(!strcmp(ft_substr("hello\nworld",idx,len - idx), "world"));
// 	// assert(!strcmp(ft_substr("hello\nworld",0,idx), "hello\n"));
// 	// assert(!strcmp(ft_substr("h",1,0), ""));
// 	// assert(!strcmp(ft_substr("\n\n",0,1), "\n"));

// 	// assert(!strcmp(ft_substr("h",0,50), "h"));
// 	// assert(ft_substr(NULL,1,0) == NULL);
// 	// assert(!strcmp(ft_strdup("hello"),"hello"));
// 	// assert(!strcmp(ft_strdup(""),""));
// 	// assert(!strcmp(ft_strdup("c"),"c"));
// 	// assert(!strcmp(ft_strdup("\n\n\n\n"),"\n\n\n\n"));
// 	// assert(!strcmp(ft_strdup("          "),"          "));
// 	// assert(ft_strdup(NULL) == NULL);

// 	// printf("%s\n",ft_strjoin("hello"," world"));
// 	// assert(!strcmp(ft_strjoin("hello"," world"),"hello world"));
// 	// assert(!strcmp(ft_strjoin("hello",NULL),"hello"));
// 	// assert(!strcmp(ft_strjoin(NULL," world")," world"));
// 	// assert(ft_strjoin(NULL,NULL) == NULL);
// 	// assert(!strcmp(ft_strjoin("\n",""),"\n"));
// 	// assert(!strcmp(ft_strjoin("",""),""));
// 	// assert(!strcmp(ft_strjoin(" "," "),"  "));
// 	// assert(!strcmp(ft_strjoin("a","b"),"ab"));
// 	// assert(!strcmp(ft_strjoin("ab","c"),"abc"));


// 	// char *line = NULL;
// 	// char *stach = "\n";

// 	// check_stach(&line,&stach);

// 	// printf("voici la ligne %s a l'adresse %p\n" ,line,line);
// 	// printf("voici la stach %s a l'adresse %p\n" ,stach,stach);

	
// 	char *str = ft_strchr("hello \n world");

// 	printf("%s\n",str + 1);

// }