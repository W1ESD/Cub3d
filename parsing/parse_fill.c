#include "parsing.h"

int     check_identifier(char   *str)
{
    return(strcmp(str,"NO") && strcmp(str,"EA") &&  \
    strcmp(str,"WE") && strcmp(str,"SO"));

}
int     check_path(char *str)
{
    int fd;
    fd = open(str,O_RDONLY);
    if(fd < 0)
        return (0);
    else
        return(1);
}

void    check_validity(char *line)
{
    char    **split;
    split = ft_split2(line);
    if(check_identifier(split[0]))
    {
        printf("eeeee\n");
        exit(0);
    }
    if(split[1] == NULL)
    {
        printf("eeeerrrrrooororooorr");
        exit(0);
    }
    if(check_path(split[1]) == 0 )
    {
        printf("a77mikrchi\n");
        exit(0);
    }
    if(split[2] != NULL)
    {
        printf("MIMIMIMIMIMIMIMIMIMIMIM");
    }
}

void    check_text(char **map)
{
    int i = 0;

    while(i < 4)
    {
        check_validity(map[i]);
        i++;
    }
}
void            parse_fill(char    **map)
{
        check_text(map);
}