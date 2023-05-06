#include "parsing.h"

char**   parse_map(char *str,t_data *data)
{
    int fd;
    char    **map;
    fd = open(str,O_RDONLY);
    if(fd < 0)
    {
        printf("%s%s\n",ERROR,FILE_NOT_FOUND);
        exit(1);
    }
    int nbr_lines = count_lines(fd);
    fd = open(str,O_RDONLY);
    map = NULL;
    map = malloc(sizeof(char*) * nbr_lines);
   	fill_map(map,fd,data);
    return(map);
}


void    init_data(t_data    *data)
{
    data->north_txt = NULL;
    data->south_txt = NULL;
    data->west_txt = NULL;
    data->east_txt = NULL;
    data->floor_color = -1;
    data->ceiling_color = -1;
    data->found_error = 0;
    data->error_msg = NULL;
    data->map = NULL;
    data->new_map = NULL;

}

void    parsing(t_data  *data,char  *map_name)
{
    init_data(data);
    if(check_name(map_name,data))
            return ;
    data->map = parse_map(map_name,data);
    parse_fill(data);
}

int     main(int    ac,char     **av)
{
    char    **map;
    t_data  *data;
    if(ac == 2)
    {
        data = malloc(sizeof(t_data));
        parsing(data,av[1]);
        if(data->found_error)
        {
            // destroy_data(data);
            printf("%s :",ERROR);
            printf("%s",data->error_msg);
            system("leaks parsing");
            return 0;
        }
        // destroy_data(data);
        printf("%s\n",data->west_txt);
        // system("leaks parsing");
    }
    return 0;
}