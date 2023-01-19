#include "get_next_line.c"
#include <stdio.h>

int main(void)
{
    int fo;
    char *next_line;
    
    fo=open("numbers copy.dict",O_RDWR);
    while (1)
    {
        next_line = get_next_line(fo);
        printf("%s",next_line);
        free(next_line);
        if(next_line == 0)
            break ;
    }  

system("leaks a.out");
}