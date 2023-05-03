#include "parsing.h"



char**   parse_map(char *str)
{
    int fd;
    char    **map;

    fd = open(str,O_RDONLY);

    if(fd < 0)
    {
        printf("%s",FILE_NOT_FOUND);
        exit(1);
    }
    int nbr_lines = count_lines(fd);

    fd = open(str,O_RDONLY);
    
    map = malloc(sizeof(char*) * nbr_lines);
    
    fill_map(map,fd);
    
    return(map);
}