/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/25 08:38:52 by wiessaiy         ###   ########.fr       */
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
	data->player.x = WINDOW_WIDTH / 2;
	data->player.y = WINDOW_HEIGHT / 2;
	data->player.width = 5;
	data->player.height = 5;
	data->player.sideDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = get_angle(parsing);
	data->player.moveSpeed = 2;
	data->player.rotationSpeed = (3 * PI) / 100;
	player_draw(data);
}

int able_to_move(t_data *data,double end_x)
{
	int my_x;
    
    int my_y;
      
    my_x =  end_x + data->player.x;
	my_y =  data->player.y;

    my_x = floor(my_x/PIXEL);
    my_y = floor(my_y/PIXEL);
    if(data->grid[my_y][my_x] == 1)
        return 0;
    return 1;
}
void	wall_collision_gliss(t_data* data,int indice)
{
	(void)data;
	if(indice == 1 && able_to_move(data,cos(data->player.rotationAngle) * data->player.moveSpeed))
		data->player.x += cos(data->player.rotationAngle) * data->player.moveSpeed;
	return ;
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
				wall_collision_gliss(data,1);
	}
	else if (data->player.walkDirection == -1)
	{
			if(able_to_walk_down(data))
			{
				data->player.x -= cos(data->player.rotationAngle) * data->player.moveSpeed;
				data->player.y -= sin(data->player.rotationAngle) * data->player.moveSpeed;
			}
			else 
				wall_collision_gliss(data,2);
	}
	if (data->player.sideDirection == 1) 
	{
		if(able_to_turn_left(data))
		{
   			data->player.x += cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
   			data->player.y += sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
		}
		else
			wall_collision_gliss(data,3);
	}
	else if (data->player.sideDirection == -1) 
	{
		if(able_to_turn_right(data))
		{	    
		data->player.x -= cos(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
	    data->player.y -= sin(data->player.rotationAngle + (PI / 2)) * data->player.moveSpeed;
		}
		else
			wall_collision_gliss(data,4);
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
    for (int i = 0; i < MAP_NUM_ROWS; i++) {
        for (int j = 0; j < MAP_NUM_COLS; j++) {
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

int update(t_data *data) 
{
	void	*img1_ptr;
	int width = WINDOW_WIDTH;
	int height = WINDOW_HEIGHT;
	if(data->op % 2 == 0)
		img1_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "frame1.xpm", &width, &height);
	else	
		img1_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "img.xpm", &width, &height);
	direction(data);
	render_map(data);
	player_draw(data);
	ray_caster(data);
	render_3d(data);
	ft_mini_map(data);
	ft_mini_map_player_render(data);
	ray_caster(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img1_ptr, 0, 0);
	mlx_clear_image(data);
	return (0);
}