#include "parsing.h"

int   skip_empty_lines(char   *line,int   nbr,int     fd)
{   
    while(line && (nbr == -1))
    {
        line = gnl(fd);
        if(line)
            nbr = empty_line(line);
    }
    if(nbr != -1)
        return 1;
    return 0;
}

void    fill_map2d(char     **map,int   fd)
{

    int     i=0;
    char    *line;
    int     nbr;
    line = gnl(fd);
    if(line)
        nbr = empty_line(line);
    if(skip_empty_lines(line,nbr,fd))
        nbr = 2;
    line = gnl(fd);
    while(line && (nbr != -1))
    {
        map[i++] = line;
        line = gnl(fd);
        if(line)
            nbr = empty_line(line);
    }
    if(skip_empty_lines(line,nbr,fd))
        nbr = 2;
    line = gnl(fd);
    if(line && (nbr != -1))
    {
        printf("%s\n",LMAP);
        exit(0);
    }
    map[i] = NULL;
}

void    fill_map(char   **map,int fd)
{
    int i = 0;
    char    *str;
    int     nbr;
    int     count = 0;
    while(1)
    {
        str = gnl(fd);
        if(str)
        {
            nbr = empty_line(str);
            if(nbr == -1)
                continue;
            else
            {
                map[i++] = str;
                count++;
            }
        }
        else
            break;
        if(count >= 6)
        {
            fill_map2d(map + i, fd);
            return;
        }
    }
    map[i] = NULL;
}