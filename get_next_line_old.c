/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:18 by amejia            #+#    #+#             */
/*   Updated: 2023/01/20 16:05:35 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char *initialize_get_next_line(int *n_char_read, char **buffer, char **leftover)
{
    if (*leftover == 0)
    {
        *leftover =(char *) ft_calloc(1,1);
        *n_char_read = BUFFER_SIZE;
    }
    if (ft_strlen(*leftover) == 0 && *n_char_read < BUFFER_SIZE)
        return 0;
    *buffer =(char *) ft_calloc(BUFFER_SIZE+1,1);
    return ((char *) ft_calloc(1,1));   
}


// lines descr
// 0 Buffer 1 line 2 position 3 temp


char *get_next_line(int fd)
{
    char **st;
    char *buffer;
    char *line;
    static char *leftover;
    static int n_char_read;
    char *position;
    char *temp;
    
    if(!(line = initialize_get_next_line(&n_char_read, st, &leftover)))
        return 0;
    while (!(position=ft_strchr(leftover,'\n')))
    {
       if(n_char_read < BUFFER_SIZE)
        {
            self_reference_free(&line,leftover,ft_strjoin);
            ft_strlcpy(leftover,"",1);
            return(free(st),line);
        } 
        else if((n_char_read = read(fd,st[0],BUFFER_SIZE)))
                self_reference_free(&leftover,st[0],ft_strjoin);
    }
    temp = ft_substr(leftover,0,(int)(position - leftover+1));
    self_reference_free(&line,temp,ft_strjoin);
    free(temp);
    temp = ft_substr(position+1,0,ft_strlen(position+1));
    free(leftover);
    leftover = temp;
    return(free(buffer),line);
}
