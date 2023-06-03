/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:52 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 03:21:32 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "parsing.h"

char**   parse_map(char *str,t_data_parsing *data)
{
    int fd;
    char    **map;
    fd = open(str,O_RDONLY);
    if(fd < 0)
    {
        printf("%s%s\n",ERROR,FILE_NOT_FOUND);
        exit(1);
    }
    int     nbr_lines = count_lines(fd,data);
    fd = open(str,O_RDONLY);
    map = NULL;
    map = malloc(sizeof(char*) * nbr_lines);
   	fill_map(map,fd,data);
    return(map);
}

void    init_data(t_data_parsing    *data)
{
    data->north_txt = NULL;
    data->south_txt = NULL;
    data->west_txt = NULL;
    data->east_txt = NULL;
    data->floor_color = 0;
    data->ceiling_color = 0; 
    data->error_msg = NULL;
    data->map = NULL;
    data->new_map = NULL;
    data->leaks_task = malloc(1000*sizeof(char *));
    data->index_leaks = 0;
}

void    save_player_position(char **map,t_data_parsing* data)
{
    int     i=0;
    int     j=0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
            {
                    data->player_y = i;
                    data->player_x = j;
                return ;
            }
            j++;
        }
        i++;
    }
    return ;
}

void    parsing(t_data_parsing  *data,char  *map_name)
{
    init_data(data);
    if(check_name(map_name))
            return ;
    data->map = parse_map(map_name,data);
    parse_fill(data);
    fill_spaces_with_walls(data);
    save_player_position(data->new_map,data);
}

