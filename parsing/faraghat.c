#include "parsing.h"

int     max_size(char   **map)
{
    int     i   = 0;
    int     nbr = 0;
    int     max = 0;

    while(map[i])
    {
        nbr = strlen(map[i]);
        if(nbr > max)
            max = nbr;
        i++;
    }
    return(max);
}

int     nbr_colone(char **map)
{
    int     i = 0;
    while(map[++i])
        i++;
    return(i);
}
void    fill_line(char  *line,char  *new_line,int max_line)
{
    int     i = 0;
    static int f=0;

    int a = strlen(line);
    
    while(i < max_line)
    {
        if(line[i] != ' ' && line[i])
            new_line[i] = line[i];
        else
            new_line[i] = '+';
        if(i > a)
            new_line[i] = '+';
        i++;
    }
    f++;
    new_line[i] = '\0';
}
void    fill_new_map(char   **map,char  **new_map,int max_line)
{
    int     i=0;
    while(map[i])
    {
        fill_line(map[i],new_map[i],max_line);
        i++;
    }
    new_map[i] = map[i];
}

int     champ(char  c)
{
    return(c == '0' || c == 'N' \
    || c == 'S' || c == 'E' || c == 'W');
}

void    check_mochkil(char  **map,int   n,int   m)
{
    int     i = 0;
    int     j = 0;

    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '+')
            {
                if(i - 1 >= 0 && i - 1 <= m)
                {
                    if(champ(map[i-1][j])){
                        printf("ERROR\n");exit(0);}
                }
                if(i + 1 >= 0 && i + 1 < m)
                {
                    if(champ(map[i+1][j])){
                        printf("ERROR\n");exit(0);}
                }
                if(j + 1 >= 0 && j + 1 <= n)
                {
                    if(champ(map[i][j+1])){
                        printf("ERROR\n");exit(0);}
                }
                if(j - 1 >= 0 && j - 1 <= n)
                {
                    if(champ(map[i][j-1])){
                        printf("ERROR L\n");exit(0);}
                }
            }
            j++;
        }
        i++;
    }
    

}
void    check_lfaraghat(char    **map)
{
    int     i=0;
    int     n = max_size(map);
    char    **new_map;
    int     collum  = nbr_colone(map) - 1;
    new_map = malloc(sizeof(char    *) * (collum + 1));
    while(i < collum + 1)
    {
        new_map[i] = malloc(n + 1);
        i++;
    }
    fill_new_map(map,new_map,n);
    check_mochkil(new_map,n,collum);
}