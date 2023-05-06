#include "parsing.h"




int check_name(char *str,t_data *data)
{   
    int  i = -1;

    while(str[++i]);
    
    i--;

    if(str[i] == 'b' && str[i-1] == 'u' && str[i-2] == 'c' && str[i-3] == '.')
        return 0;
    else
    {
        data->error_msg = NAME_ERROR;
        data->found_error = 1;
        return 1;
    }
}


int     count_lines(int fd)
{
    int count = 0;
    char    *line;

    line = gnl(fd);
    while(line)
    {
        count++;
        free(line);
        line = gnl(fd);
    }
    close(fd);
    return(count);
}

int     valid_line(char *line)
{
    int     i = 0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\n')
            return(1);
        i++;
    }
    return(0);
}

