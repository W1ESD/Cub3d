#include "parsing.h"

void    add_text_to_struct(char *ident,char *line,t_data*   data)
{
    if(ident[0] == 'N')
        data->north_txt = strdup(line);
    if(ident[0] == 'S')
        data->south_txt = strdup(line);
    if(ident[0] == 'E')
        data->east_txt = strdup(line);
    if(ident[0] == 'W')
        data->west_txt = strdup(line);
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
int     check_identifier(char   *str)
{
    return(strcmp(str,"NO") && strcmp(str,"EA") &&  \
    strcmp(str,"WE") && strcmp(str,"SO"));

}
void    check_validity(char *line,t_data* data)
{
    char    **split;
    static int a;
    split = ft_split2(line);
    if(check_identifier(split[0]))
    {
        printf("%s%s\n",ERROR,"Invalid Identifier for Texter\033[0m");
        exit(1);
    }
    if(split[1] == NULL)
    {
        printf("%s%s\n",ERROR,"Invalid texter\033[0m");
        exit(1);
    }
    if(check_path(split[1]) == 0 )
    {
        printf("%s%s\n",ERROR,"Invalid texter path\033[0m");
        exit(1);
    }

    if(split[2] != NULL)
    {
        printf("%s%s\n",ERROR,"Invalid Line for texters\033[0m");
        exit(1);
    }
    add_text_to_struct(split[0],split[1],data);
    int i = 0;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
    a++;
}

void    check_text(t_data* data)
{
    int i = 0;

    while(i < 4)
    {
        check_validity(data->map[i],data);
        i++;
    }
    printf("%s\n",data->south_txt);
    printf("%s\n",data->north_txt);
    printf("%s\n",data->west_txt);
    printf("%s\n",data->east_txt);
}