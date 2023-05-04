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

void    check_duplicity(char    **map)
{
    int  i=0;
    int j;
    while(i < 4)
    {
        j = i + 1;
        while(j < 4)
        {
            if(map[i][0] == map[j][0])
            {
                printf("errrrrnoo duplicated identifier");
                exit(-1);
            }
            j++;
        }
        i++;
    }
}

int     count_coma(char *line)
{
    int     i = 0;
    int     count=0;
    while (line[i])
    {   
        if(line[i] == ',')
            count++;
    i++;
    }
    return(count);
}

int     count_bits(char     *line)
{
    int     i=0;
    while(line[i])
    {
        if(i > 2)
            return (1);
        i++;
    }
    return(0);
}

void    check_valid_bit(char    *line)
{
    if(!line)
    {
        printf("ERROR");
        exit(0);
    }
    if(count_bits(line))
    {
        printf("EEEEERROROROROROROROORRORRRRRR\n");
        exit(0);
    }
    int     c = ft_atoi(line);
    printf("line is : %s int is : %d\n",line,c);
    if( c > 255 || c == -1)
    {
        printf("ERRRRRPRTKKKJK\n");
        exit(0);
    }

}

void    check_format(char   *line)
{
    int     i = 0;
    while (line[i] == ' ' || line[i] == '\t')
            i++;
    int coma = count_coma(line + i);
    if(coma != 2)
    {
        printf("ERROR");
        exit(0);
    }
    char    **split = NULL;
    split = ft_split2_2(line + i);
    int     j=0;
    while(j < 3)
    {
        check_valid_bit(split[j]);
        j++;
    }

}

void    check_flor(char     *line)
{
    if(line[0] != 'F' && line[0] != 'C' && line[1] != ' ')
    {
        printf("sshhhshshhs\n");
        exit(0);
    }
    check_format(line + 1);

}

void    check_colors(char       **map)
{
    check_flor(map[4]);
    check_flor(map[5]);
}

void    check_map_game(char **map)
{

    
}

void            parse_fill(char    **map)
{
    check_text(map);
    check_duplicity(map);
    check_colors(map);
    check_map_game(map);
}
