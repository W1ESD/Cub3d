#include "parsing.h"


int main(int ac,char **av)
{

    char    **map;

    if(ac == 2)
    {

    if(check_name(av[1]))
        return (0);
    
    map = parse_map(av[1]);
    }
    return 0;
}