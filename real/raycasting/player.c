/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/31 15:51:15 by wiessaiy         ###   ########.fr       */
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

void render_player(t_data *data,t_data_parsing *parsing)
{
	data->player.x = (parsing->player_x) * PIXEL;
	data->player.y = (parsing->player_y) * PIXEL;
	data->player.width = 5;
	data->player.height = 5;
	data->player.sideDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = get_angle(parsing);
	data->player.moveSpeed = 2;
	data->player.rotationSpeed = (3 * PI) / 100;
	player_draw(data);
}

int able_to_x(t_data *data)
{
	int my_x;

    int my_y;

	int x;

	int y;

    my_x =  data->player.x + cos(data->player.rotationAngle) * data->player.moveSpeed;
	my_y =  data->player.y;


    x = floor(my_x/PIXEL);
    y = floor(my_y/PIXEL);

	if(data->grid[y][x] == 1)
        return 0;

	return 1;
}
int able_to_y(t_data *data)
{
	int my_x;

    int my_y;

	int x;

	int y;

    my_x =  data->player.x;
	my_y =  data->player.y + sin(data->player.rotationAngle) * data->player.moveSpeed;


    x = floor(my_x/PIXEL);
    y = floor(my_y/PIXEL);

	if(data->grid[y][x] == 1)
        return 0;

	return 1;
}

int really_able(t_data* data,int ind)
{
	int 	a = 0;
	int  	my_x;
	int 	my_y;
	int 	new_x;
	int 	new_y;

	if(ind == 1)
	{

	my_x = data->player.x + cos(data->player.rotationAngle) * data->player.moveSpeed;
	my_y = data->player.y;

	new_x = floor(my_x/PIXEL);
	new_y = floor(my_y/PIXEL);

	if(data->grid[new_y][new_x] == 1)
		a++;

	my_x = data->player.x;
	my_y = data->player.y + sin(data->player.rotationAngle) * data->player.moveSpeed;

	if(my_y % PIXEL == 0)
		my_y--;
	new_x = floor(my_x/PIXEL);
	new_y = floor(my_y/PIXEL);

	if(data->grid[my_y][my_x] == 1)
		a++;
	if(a == 2 || a == 1)
		return (0);
	}

	return 1;
}

void direction(t_data *data)
{		
	if (data->player.walkDirection == 1)
	{
			if(able_to_walk_up(data) && really_able(data,1))
			{
				data->player.x += cos(data->player.rotationAngle) * data->player.moveSpeed;
				data->player.y += sin(data->player.rotationAngle) * data->player.moveSpeed;
			}
	}
	else if (data->player.walkDirection == -1)
	{
			if(able_to_walk_down(data))
			{
				data->player.x -= cos(data->player.rotationAngle) * data->player.moveSpeed;
				data->player.y -= sin(data->player.rotationAngle) * data->player.moveSpeed;
			}
	}
	if (data->player.sideDirection == 1) 
	{
		if(able_to_turn_left(data))
		{
   			data->player.x += cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
   			data->player.y += sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
		}
	}
	else if (data->player.sideDirection == -1) 
	{
		if(able_to_turn_right(data))
		{	    
		data->player.x -= cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
	    data->player.y -= sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
		}
	}
}

void mlx_clear_image(t_data *data)
{
	int x, y;
	int color = BLACK_COLOR;
	for (x = 0; x < WINDOW_WIDTH; x++)
	{
		for (y = 0; y < WINDOW_HEIGHT; y++)
			my_mlx_pixel_put(&data->img, x, y, color);
	}
}


int update(t_data *data) 
{
	
	direction(data);
	render_map(data);
	player_draw(data);
	ray_caster(data);
	render_3d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	mlx_clear_image(data);
	
	return (0);
}