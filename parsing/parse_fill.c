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
    // printf("line is : %s int is : %d\n",line,c);
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

void    check_vl(char   *s)
{
    int     i = 0;
    while(s[i])
    {
        if(s[i] != '1' && s[i] != '0' && s[i] != 'N'  \
            && s[i] != 'S' && s[i] != 'E' && s[i] != 'W' && s[i] != ' ')
            printf("COMPOSANT WRONG\n");
        i++;
    }
}
void    check_different_digit(char  **map)
{
    int     i = 6;
    while(map[i])
    {
        check_vl(map[i]);
        i++;
    }
}
void    check_player_duplicity(char **map)
{
    int     i = 6;
    int     j;
    int     count = 0;
    while (map[i])
    {
        j=0;
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
                count ++;
            j++;
        }
        i++;
    }
    if(count > 1)
    {
        printf("\nerrorduplicateplayer\n\n");
        exit(0);
    }
}
void    first_line(char *line)
{
    int     i = 0;
    while(line[i])
    {
        if(line[i] != '1' && line[i] != ' ')
        {
            printf("errno\n");
            exit(0);
        }
        i++;
    }
}
void    check_first_last(char   *line)
{
    int     i=0;
    if(line[i] != '1' && line[i] != ' ')
    {
        printf("ERROR foundddddd \n");
        exit(0);
    }
    while(line[++i]);
    if(line[i-1] != '1' && line[i-1] != ' ')
    {
        printf("NOT 1 FOUNDED\n");
        exit(0);
    }
}
void    check_lastline(char *line)
{
    int     i=0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '1')
        {
            printf("DDDD_DDD LAST LINE");
            exit(0);
        }
        i++;
    }
}
void    enc_map(char **map)
{
    int     i=0;
    while(map[i])
    {
        check_first_last(map[i]);
        i++;
    }
    check_lastline(map[i-1]);
}
void    closed_map(char **map)
{
    first_line(map[0]);
    enc_map(map);
}

void    check_map_game(char **map)
{
    check_different_digit(map);
    check_player_duplicity(map);
    closed_map(map + 6);
}

void            parse_fill(char    **map)
{
    check_text(map); 
    check_duplicity(map);
    check_colors(map);
    check_map_game(map); 
    check_lfaraghat(map+6);
}
 