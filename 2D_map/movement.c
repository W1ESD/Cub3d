/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:06 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/28 23:01:14 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

   
#include "header.h"
   
int     able_to_walk_up(t_data *data) 
{
    int my_x;
        
    int my_y;
          
    my_x = cos(data->player.rotationAngle) * data->player.moveSpeed + data->player.x;
	my_y = sin(data->player.rotationAngle) * data->player.moveSpeed + data->player.y;
    
    if(my_y % PIXEL  == 0)
        my_y--;

    my_x = floor(my_x/PIXEL);
    my_y = floor(my_y/PIXEL);

    if(data->grid[my_y][my_x] == 1)
        return 0;
    return 1;    
}

int     able_to_walk_down(t_data *data)
{
    int my_x;
    int my_y;
	
    my_x = data->player.x - cos(data->player.rotationAngle) * data->player.moveSpeed;
	my_y = data->player.y - sin(data->player.rotationAngle) * data->player.moveSpeed;
    
    
    my_x = floor(my_x/PIXEL);
    my_y = floor(my_y/PIXEL);
    
    if(data->grid[my_y][my_x] == 1)
        return 0;
    return 1;
}
int     able_to_turn_left(t_data *data)
{
    
    int my_x;
    int my_y;

    
    my_x  = data->player.x + cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
    if(my_x % PIXEL == 0)
        my_x--;
    my_y = data->player.y + sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;

    my_x = floor(my_x/PIXEL);
    my_y = floor(my_y/PIXEL);
        
    if(data->grid[my_y][my_x] == 1)
            return 0;
    return 1;
}
int     able_to_turn_right(t_data *data)
{
    
    int my_x;
    int my_y;

    my_x = data->player.x - cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
    my_y = data->player.y - sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;

    my_x = floor(my_x/PIXEL);
    my_y = floor(my_y/PIXEL);
        
    if(data->grid[my_y][my_x] == 1)
        return 0;
    return 1;
}