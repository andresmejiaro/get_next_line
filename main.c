
#include "get_next_line_utils.c"
#include "get_next_line.c"
#include <stdio.h>

int main(void)
{
    int fo;
    int fo2;
    char *next_line;
    char buffer[30];

    fo=open("41_no_nl",O_RDWR);
    while (1)
    {
        next_line = get_next_line(fo);
        printf("%s",next_line);
        
    }  
system("leaks a.out");
}