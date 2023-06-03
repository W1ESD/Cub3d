/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/03 03:35:30 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void render_player(t_data *data,t_data_parsing *parsing)
{
	data->player.x = (parsing->player_x) * data->tile_size;
	data->player.y = (parsing->player_y) * data->tile_size;
	data->player.width = 5;
	data->player.height = 5;
	data->player.sideDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = get_angle(parsing);
	data->player.moveSpeed = 2;
	data->player.rotationSpeed = (3 * PI) / 100;
}

int able_to_x(t_data *data)
{
	int my_x;

    int my_y;

	int x;

	int y;

    my_x =  data->player.x + cos(data->player.rotationAngle) * data->player.moveSpeed;
	my_y =  data->player.y;


    x = floor(my_x/data->tile_size);
    y = floor(my_y/data->tile_size);

	if (x < data->cols && my_y < data->rows)
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


    x = floor(my_x/data->tile_size);
    y = floor(my_y/data->tile_size);

	if (x < data->cols && y < data->rows)
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

	new_x = floor(my_x/data->tile_size);
	new_y = floor(my_y/data->tile_size);

	if (new_x < data->cols && new_y < data->rows)
		if(data->grid[new_y][new_x] == 1)
			a++;

	my_x = data->player.x;
	my_y = data->player.y + sin(data->player.rotationAngle) * data->player.moveSpeed;

	if(my_y % (int)data->tile_size == 0)
		my_y--;
	new_x = floor(my_x/data->tile_size);
	new_y = floor(my_y/data->tile_size);

	if (my_x < data->cols && my_y < data->rows)
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



int update(t_data *data) 
{	   
	direction(data);
	ray_caster(data);
	render_3d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}   