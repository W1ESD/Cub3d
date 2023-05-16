/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:02 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/17 00:44:10 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
 
int	close_window(void)
{
	exit (0);
}

int key_pressed(int keycode, t_player *player)
{
		if (keycode == W_KEY )
    	    player->walkDirection = 1;
    	else if (keycode == S_KEY )
    	    player->walkDirection = -1;
    	else if (keycode == A_KEY )
    	    player->sideDirection = -1;
    	else if (keycode == D_KEY )
    	    player->sideDirection = 1;
		if (keycode == LEFT_KEY)
			player->rotationAngle -=  player->rotationSpeed;
		else if (keycode == RIGHT_KEY)
			player->rotationAngle +=  player->rotationSpeed;
	if (keycode == ESC)
		close_window();
    return (0);
}

int key_released(int keycode, t_player *player)
{

    if (keycode == W_KEY || keycode == S_KEY)
        player->walkDirection = 0;
    else if (keycode == A_KEY || keycode == D_KEY)
        player->sideDirection = 0;
    return (0);
}