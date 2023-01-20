#include "get_next_line.h"

int check_errors(fd)
{
    if (fd <0 || fd > 1023 || read(fd,0,0) == -1)
		return (0);
    return (1);
}


char *create_line_from_left(char **left)
{
    char *breakpoint;
    char *before;
    char *after;
    char *old;

    breakpoint = ft_strchr(*left,'\n');
    if (breakpoint == 0)
        return(*left);
    before = ft_substr(*left,0,(int)(breakpoint - *left+1));
    after = ft_substr(breakpoint+1,0,ft_strlen(breakpoint+1));
    old = *left;
    *left = after;
    free(old);
    return(before);
}

char *read_from_file(int fd,char **left)
{
    char buffer[BUFFER_SIZE+1];
    char *old;
    int k;

    k=-1;
    while(k++ < BUFFER_SIZE )
        buffer[k]='\0';
    if(*left == 0)
        *left = ft_calloc(1,1);
    if((read(fd,buffer,BUFFER_SIZE)))
    {
        old = *left;
        *left=ft_strjoin(*left,buffer);
        free(old);
        if(ft_strchr(*left,'\n'))
            return(create_line_from_left(left));
        else
            return(read_from_file(fd,left));
    }
    else if(ft_strlen(*left)==0)
    {
        free(*left);
        *left = 0;
        return(0);
    }
    else
        old = ft_substr(*left,0,ft_strlen(*left));
        free (*left);
        *left = 0;
        return(old);
}

char *get_next_line(int fd)
{
    static char *left;

    if (!check_errors(fd))
        return 0;
    if (left != 0 && ft_strchr(left,'\n'))
        return(create_line_from_left(&left));
    else 
        return(read_from_file(fd,&left));
}

