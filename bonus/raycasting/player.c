/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/01 16:42:20 by wiessaiy         ###   ########.fr       */
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

	if (x < data->cols && y < data->rows)
		if(data->grid[y][x] == 1 || data->grid[y][x] == 6)
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

	if (x < data->cols && y < data->rows)
		if(data->grid[y][x] == 1 || data->grid[y][x] == 6)
        	return 0;
	return 1;
}

void	wall_collision_gliss(t_data* data)
{
	if(able_to_x(data))
	{
		data->player.x +=  cos(data->player.rotationAngle) * data->player.moveSpeed;
	}
	if(able_to_y(data))
	{
		data->player.y += sin(data->player.rotationAngle) * data->player.moveSpeed;
	}
	return ;
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

	if (new_x < data->cols && new_y < data->rows)
		if(data->grid[new_y][new_x] == 1)
			a++;

	my_x = data->player.x;
	my_y = data->player.y + sin(data->player.rotationAngle) * data->player.moveSpeed;

	if(my_y % PIXEL == 0)
		my_y--;
	new_x = floor(my_x/PIXEL);
	new_y = floor(my_y/PIXEL);

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
			if(able_to_walk_up(data))
			{
				data->player.x += cos(data->player.rotationAngle) * data->player.moveSpeed;
				data->player.y += sin(data->player.rotationAngle) * data->player.moveSpeed;
			}
			else
				wall_collision_gliss(data);
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

void	ft_mini_map(t_data* data)
{
	
	int x, y, color;
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            x = j * PIXEL;
            y = i * PIXEL;
            color = data->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            for (int dx = 0; dx < PIXEL; dx++) {
                for (int dy = 0; dy < PIXEL; dy++) {
                    my_mlx_pixel_put(&data->img, (x + dx) * MINI_MAP_SCALE_FACTOR, \
					(y + dy) * MINI_MAP_SCALE_FACTOR, color);
                }
            }
        }
    }
	
}

void ft_mini_map_player_render(t_data *data) 
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

void	render_animation(t_data* data)
{
	if(data->op){
	int pid=fork();
	if(!pid)
	{
	char *a = "/usr/bin/afplay";
    char *cmd[3];
    cmd[0] = "afplay";
    cmd[1] = "audio1.wav";
    cmd[2]  = NULL;
    execve(a, cmd, NULL);
	}
	int i=0;

	while (i < 29)
	{
		update2(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->iimg[i], 0, 0);
		mlx_do_sync(data->mlx_ptr);
		i++;
 	}
		data->op = 0;
	}
	return ;
}


int update(t_data *data) 
{
	
	direction(data);
	render_map(data);
	player_draw(data);
	ray_caster(data);
	render_3d(data);
	ft_mini_map(data);
	ft_mini_map_player_render(data);
	ray_caster(data);
	render_animation(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1_ptr, 0, 0);
	mlx_clear_image(data);
	
	return (0);
}