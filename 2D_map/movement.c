/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:06 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/11 14:12:38 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int     able_to_walk_up(t_player* player) 
{
        int my_x;
        int my_y;
        
    	my_x = cos(player->rotationAngle) * player->moveSpeed + player->x;
		my_y = sin(player->rotationAngle) * player->moveSpeed + player->y;
        if(player->grid[my_y/PIXEL][my_x/PIXEL] == 1)
            return 0;
        return 1;
}

int     able_to_walk_down(t_player* player)
{
        int my_x;
        int my_y;
		
        my_x = player->x - cos(player->rotationAngle) * player->moveSpeed;
		my_y = player->y - sin(player->rotationAngle) * player->moveSpeed;

        if(player->grid[my_y/PIXEL][my_x/PIXEL] == 1)
            return 0;
        return 1;
}
int     able_to_turn_left(t_player *player)
{
    
    int my_x;
    int my_y;

    my_x = player->x - player->moveSpeed;
    my_y = player->y;
    if(player->grid[my_y/PIXEL][my_x/PIXEL] == 1)
        return 0;
    return 1;
}
int     able_to_turn_right(t_player *player)
{
    
    int my_x;
    int my_y;

    my_x = player->x + player->moveSpeed;
    my_y = player->y;
    if(player->grid[my_y/PIXEL][my_x/PIXEL] == 1)
        return 0;
    return 1;
}

int     able_to_move(t_player*  player,int  move)
{

if(move == 1 && able_to_walk_up(player))
    return 1;
if(move == 2 && able_to_walk_down(player))
    return 1; 
if(move == 3 && able_to_turn_left(player))
    return 1;
if(move == 4 && able_to_turn_right(player))
    return 1;
return 0;

}