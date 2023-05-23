/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:18:28 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/23 08:40:26 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    fill_spaces_with_walls(t_data_parsing* data)
{
    int i=0;
    int j=0;
    while(data->new_map[i])
    {    
        j=0;
        while(data->new_map[i][j])
        {
            if(data->new_map[i][j] == '+')
                    data->new_map[i][j] = '1';
            j++;
        }
        i++;
    }
    return;    
}