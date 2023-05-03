#include "parsing.h"

int check_name(char *str)
{   
    int  i = -1;

    while(str[++i]);
    
    i--;

    if(str[i] == 'b' && str[i-1] == 'u' && str[i-2] == 'c' && str[i-3] == '.')
        return 0;
    else
    {
        printf("%s\n",NAME_ERROR);
        return 1;
    }
}
int     count_lines(fd)
{
    int count = 0;
    while(gnl(fd))
        count++;
    close(fd);
    return(count);
}
int     empty_line(char *str)
{
    int     i = 0;

    while(str[i])
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\n')
            return(strlen(str));
        i++;
    }
    return (-1);
}






