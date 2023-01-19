/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:18 by amejia            #+#    #+#             */
/*   Updated: 2023/01/19 23:42:40 by amejia           ###   ########.fr       */
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

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    static char *leftover;
    static int n_char_read;
    char *position;
    char *temp;
    
    if(!(line = initialize_get_next_line(&n_char_read, &buffer, &leftover)))
        return 0;
    while (!(position=ft_strchr(leftover,'\n')))
    {
       if(n_char_read < BUFFER_SIZE)
        {
            self_reference_free(&line,leftover,ft_strjoin);
            ft_strlcpy(leftover,"",1);
            return(free(buffer),line);
        } 
        else if((n_char_read = read(fd,buffer,BUFFER_SIZE)))
                self_reference_free(&leftover,buffer,ft_strjoin);
    }
    temp = ft_substr(leftover,0,(int)(position - leftover+1));
    self_reference_free(&line,temp,ft_strjoin);
    free(temp);
    temp = ft_substr(position+1,0,ft_strlen(position+1));
    free(leftover);
    leftover = temp;
    return(free(buffer),line);
}
