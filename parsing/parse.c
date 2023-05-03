#include "parsing.h"


int main(int ac,char **av)
{

    char    **map;
    int     nbr;

    if(ac == 2)
    {

    if(check_name(av[1]))
        return (0);
    
    map = parse_map(av[1]);
    int     i = -1;

    while(map[++i]);
    if(i <= 6)
    {
        printf("ERROR FOUNDED\n");
        exit(0);
    }
    parsing(map);
    }
    return 0;
}