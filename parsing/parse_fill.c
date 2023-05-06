#include "parsing.h"

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

void            parse_fill(t_data* data)
{
    check_text(data); 
    check_duplicity(data->map);
    check_colors(data);
    check_map_game(data);
    // system("leaks parsing");
    check_lfaraghat(data->map + 6,data);
}
