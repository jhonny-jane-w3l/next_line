/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:13:38 by cw3l              #+#    #+#             */
/*   Updated: 2024/11/09 21:03:52 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line_test.h"

void test_module()
{
	//stach processing;

	char *stach = strdup("\n\n\n\n\n\n\n");
	char *line = NULL;
	
    int i = 1;
    int len = ft_len_index_of(stach,'l');

    //verifier la decrementation de la variable static en entré;
    //verifie line == \n
    
    while (stach)
    {   
        printf("voici la'adresse en entre de la varible static %p\n", stach);
        printf("voici la'adresse en entre de la ligne %p\n", line);

        ft_stach_processing(&stach, &line);
        
        printf("\nvoici la'adresse en sortie de la varible static %p\n", stach);
        printf("voici la'adresse en sortie de la ligne %p\n\n\n", line);
        
        assert(!strcmp(line,"\n"));
        assert(ft_len_index_of(stach,'l') == len - i);
        free(line);
        line = NULL;
        i++;
    }

    assert(line == NULL);
    
    stach = strdup("hello\nworld");
    ft_stach_processing(&stach, &line);
    
    assert(!strcmp(line,"hello\n"));
    assert(!strcmp(stach,"world"));
    
    free(stach);
    
    stach = strdup("world\n");
    line = NULL;
    
    ft_stach_processing(&stach, &line);
    
    assert(!strcmp(line,"world\n"));
    assert(stach == NULL);
    
    stach = strdup("world\n");
    line = NULL;
    
    ft_stach_processing(&stach, &line);
    
    assert(!strcmp(line,"world\n"));
    assert(stach == NULL);
    
    // C'est la fonction get next line qui gere les stach pleine sans \n
}

int main(void)
{

    test_module();
    return (0);
}