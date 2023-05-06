#include "parsing.h"

int     check_path(char *str)
{
    int fd;
    fd = open(str,O_RDONLY);
    if(fd < 0)
        return (0);
    else
        return(1);
}
int     check_identifier(char   *str)
{
    return(strcmp(str,"NO") && strcmp(str,"EA") &&  \
    strcmp(str,"WE") && strcmp(str,"SO"));

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
    int i=0;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void    check_text(t_data* data)
{
    int i = 0;

    while(i < 4)
    {
        check_validity(data->map[i]);
        i++;
    }
}