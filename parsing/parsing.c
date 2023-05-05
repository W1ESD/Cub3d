#include "parsing.h"

int     valid_line(char *line)
{
    int     i = 0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\n')
            return(1);
        i++;
    }
    return(0);
}

void    follow_to_map(char  **map,int   fd)
{
    char    *line = gnl(fd);
    char    *liste = NULL;
    int     n;

    map[6] = NULL;
    if(line)
        n = valid_line(line);
    while(line && !n)
    {
        line = gnl(fd);
        if(line)
            n = valid_line(line);
    }
    int         i = 6;
    while(1)
    {
        if(!line)
            break;
        liste = ft_strjoin(liste, line);
        line = gnl(fd);
        if(line)
            n = valid_line(line);
        if(!n || !line)
            break;
    }
    while(line && !n)
    {
        line = gnl(fd);
        if(line)
            n = valid_line(line);
    }
    if(line && n)
    {
        printf("ERROOOOR\n");
        exit(0);
    }
    char    **splited_map=NULL;
    if(liste)
        splited_map = ft_split(liste,'\n');
    int     j = 0;
    if(splited_map){
    while(splited_map[j])
    {   
        map[i] = splited_map[j];
        i++;
        j++;
    }}
    map[i] = NULL;
    if(!map[6])
    {
        printf("ERRRNRRRRRRRRENENENENEN");
        exit(0);
    }
}

void    fill_map(char   **map,int fd)
{
   char     *line;
   int      count = 0;
   line = gnl(fd);
   char     *liste;

   while (line)
   {    
        if(valid_line(line))
        {
            liste = ft_strjoin(liste,line);
            count++;
        }
        if(count >= 6)
            break;
        line = gnl(fd);
   }

   char     **split;
   int      i=0;
   split = ft_split(liste,'\n');

   if(count < 6)
   {
        printf("Error Occured");
        exit(0);
   }

   while (split[i])
   {
        map[i] = split[i];
        i++;
   }
   follow_to_map(map,fd);
}


int     main(int    ac,char     **av)
{
    char    **map;
    int     nbr; 
    if(ac == 2) 
    {
        if(check_name(av[1]))
            return 0;
    }
    map = parse_map(av[1]);
    parse_fill(map); 
    return 0;
}