/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/31 13:39:04 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void player_draw(t_data *data) 
{
	int x, y, color;
	
	x = data->player.x;
	
	y = data->player.y;
	    
	color = WHITE_COLOR;
	for (int i = 0; i < data->player.width; i++) {
		for (int j = 0; j < data->player.height; j++) {
			my_mlx_pixel_put(&data->img, (x + i) * MINI_MAP_SCALE_FACTOR, \
			(y + j) * MINI_MAP_SCALE_FACTOR, color);
		}
	}
}

void render_player(t_data *data, t_data_parsing *parsing)
{
	data->player.x = WINDOW_WIDTH / 2;
	data->player.y = WINDOW_HEIGHT / 2;
	data->player.width = 5;
	data->player.height = 5;
	data->player.sideDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = get_angle(parsing);
	data->player.moveSpeed = 2;
	data->player.rotationSpeed = (3 * PI) / 100;
	// player_draw(data);
}

void direction(t_data *data)
{		
	if (data->player.walkDirection == 1 && able_to_walk_up(data))
	{
		data->player.x += cos(data->player.rotationAngle) * data->player.moveSpeed;
		data->player.y += sin(data->player.rotationAngle) * data->player.moveSpeed;
	}
	else if (data->player.walkDirection == -1 && able_to_walk_down(data))
	{
		data->player.x -= cos(data->player.rotationAngle) * data->player.moveSpeed;
		data->player.y -= sin(data->player.rotationAngle) * data->player.moveSpeed;
	}
	if (data->player.sideDirection == 1 && able_to_turn_left(data)) 
	{
   		data->player.x += cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
   		data->player.y += sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
	}
	else if (data->player.sideDirection == -1 && able_to_turn_right(data)) 
	{
	    data->player.x -= cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
	    data->player.y -= sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
	}
}

int update(t_data *data) 
{
	data->player.slide_left = 0;
	data->player.slide_right = 0;
	direction(data);
	// render_map(data);
	// player_draw(data);
	ray_caster(data);
	render_3d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}
