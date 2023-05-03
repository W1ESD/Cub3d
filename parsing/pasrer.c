#include "parsing.h"

void    check_line(char *line)
{
    char    **split = ft_split(line,' ');
    printf("split[0]:%s split[1] %s",split[0],split[1]);
    if(strcmp(split[0],"NO") && strcmp(split[0],"SO") && strcmp(split[0],"EA") && strcmp(split[0],"WE"))
    {
        printf("ERROR\n");
        exit(0);
    }
    if(strcmp(split[1],"\n") == 0)
    {
        printf("RRRRRRRRRRRRRRRRRRRPPPPPP");
        exit(0);
    }
}


void    parse_texters(char  *line1,char *line2,char *line3,char *line4)
{
    check_line(line1);
    check_line(line2);
    check_line(line3);
    check_line(line4);
}

void    parsing(char    **map)
{

    parse_texters(map[0],map[1],map[2],map[3]);

    return;
}