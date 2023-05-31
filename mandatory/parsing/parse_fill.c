/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:38 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/28 23:08:56 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    check_duplicity(char    **map)
{
    int  i=0;
    int j;
    while(i < 6)
    {    
        j = i + 1;
        while(j < 6)
        {
            if(map[i][0] == map[j][0])
            {
                printf("%s%s\n",ERROR,"Duplicate Identifier Founded\033[0m");
                exit(1);
            }
            j++;
        }
        i++; 
    }
    // printf("hello\n");
}

void            parse_fill(t_data_parsing* data)
{
    
    check_text(data);
    check_duplicity(data->map);
    check_colors(data);
    check_map_game(data);
    check_lfaraghat(data->map + 6,data);
}
