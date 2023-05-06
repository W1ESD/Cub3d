#include "parsing.h"
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
void    check_different_digit(t_data  *data)
{
    int     i = 6;
    while(data->map[i])
    {
        check_vl(data->map[i]);
        i++;
    }
}
void    check_player_duplicity(t_data   *data)
{
    int     i = 6;
    int     j;
    int     count = 0;
    while (data->map[i])
    {
        j=0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'W' || data->map[i][j] == 'S')
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
void    check_map_game(t_data *data)
{
    check_different_digit(data);
    check_player_duplicity(data);
    closed_map(data->map + 6);
}