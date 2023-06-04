/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 05:17:27 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"   

double adjust_angle(double angle)   
{
    angle = fmod(angle, 2 * PI);      
    if (angle < 0) { 
        angle = (2 * PI) + angle;
    }   
    return angle;   
}    
  
int found_Wall(t_data *data, int x, int y)
{
    int my_x;
    int my_y;
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
            return 1;
    my_x = floor(x / data->tile_size);
    my_y = floor(y / data->tile_size);
    if (my_x < data->cols && my_y < data->rows)
	{
		if(data->grid[my_y][my_x] == 1)
		{
			if(data->x_door == my_x && data->y_door == my_y)
				return 2;
    		return 1;
		}
	}
    return 0; 
}
int to_door(t_data *data, int x, int y)
{
    int my_x;
    int my_y;
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
            return 1;
    my_x = floor(x / data->tile_size);
    my_y = floor(y / data->tile_size);
    if (my_x < data->cols && my_y < data->rows)
		if(data->grid[my_y][my_x] == 6)
    		return 1;
    return 0; 
}

int is_ray_facing_down(double my_angle)
{
	if (my_angle > 0 && my_angle < PI)
		return 1;
	return 0;
}

int is_ray_facing_right(double my_angle)
{
	if (my_angle < PI / 2 || my_angle > 3 * PI / 2)
		return 1;
	return 0;
}

int   horizontal_intersection(t_data *data, int i)
{
	int index = 0;
    data->ray[i].y_intercept = floor(data->player.y / data->tile_size) * data->tile_size;
    if(is_ray_facing_down(data->ray[i].ray_angle))
        data->ray[i].y_intercept += data->tile_size;
	
    data->ray[i].x_intercept = data->player.x + (data->ray[i].y_intercept - data->player.y) / tan(data->ray[i].ray_angle);
    
	data->ray[i].y_step = data->tile_size;
    if(!is_ray_facing_down(data->ray[i].ray_angle))
        data->ray[i].y_step *= -1;
    
	data->ray[i].x_step  = data->tile_size / tan(data->ray[i].ray_angle);
    if(data->ray[i].x_step > 0  && !is_ray_facing_right(data->ray[i].ray_angle))
        data->ray[i].x_step *= -1;
	if(data->ray[i].x_step < 0 && is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].x_step *= -1;
    
	data->ray[i].next_horz_x = data->ray[i].x_intercept ;
    data->ray[i].next_horz_y = data->ray[i].y_intercept ;
	
	if (!is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].next_horz_y--;
	
	while(data->ray[i].next_horz_x >= 0 &&  data->ray[i].next_horz_x <= WINDOW_WIDTH \
	&& data->ray[i].next_horz_y >=0 && data->ray[i].next_horz_y <= WINDOW_HEIGHT )
    {	
		index = found_Wall(data, data->ray[i].next_horz_x, data->ray[i].next_horz_y);
        if(index)
        {
                data->ray[i].hit_x_h = data->ray[i].next_horz_x;
                data->ray[i].hit_y_h = data->ray[i].next_horz_y;
				if(index == 2)
					data->ray[i].found_door = 1;
                return 1;
        }
        else
        {
            // if(to_door(data,data->ray[i].next_horz_x,data->ray[i].next_horz_y))
            // {
            //     data->ray[i].hit_x_h = data->ray[i].next_horz_x;
            //     data->ray[i].hit_y_h = data->ray[i].next_horz_y;
            //     data->ray[i].found_door = 1;
            //     return 1;
            // }
            data->ray[i].next_horz_x += data->ray[i].x_step;
            data->ray[i].next_horz_y += data->ray[i].y_step;
        }
	}
	return 0;
}

int   vertical_intersection(t_data *data, int i)
{
	int index = 0;
	data->ray[i].x_intercept = floor(data->player.x/data->tile_size) * data->tile_size;
	if(is_ray_facing_right(data->ray[i].ray_angle))
        data->ray[i].x_intercept += data->tile_size;
    
	data->ray[i].y_intercept = data->player.y + (data->ray[i].x_intercept - data->player.x) * tan(data->ray[i].ray_angle);
    
	data->ray[i].x_step = data->tile_size;
	if(!is_ray_facing_right(data->ray[i].ray_angle))
        data->ray[i].x_step *= -1;
    
	data->ray[i].y_step  = data->tile_size * tan(data->ray[i].ray_angle);
    if(data->ray[i].y_step > 0  && !is_ray_facing_down(data->ray[i].ray_angle))
        data->ray[i].y_step *= -1;
	else if(data->ray[i].y_step < 0 && is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].y_step *= -1;
    
	data->ray[i].next_vert_x = data->ray[i].x_intercept ;
    data->ray[i].next_vert_y = data->ray[i].y_intercept ;
	
	if (!is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].next_vert_x--;
    while(data->ray[i].next_vert_x >= 0 && data->ray[i].next_vert_x <= WINDOW_WIDTH && \
	data->ray[i].next_vert_y >=0 && data->ray[i].next_vert_y <= WINDOW_HEIGHT )
    {	
		index = found_Wall(data, data->ray[i].next_vert_x, data->ray[i].next_vert_y);
        if(index)
        {
                data->ray[i].hit_x_v = data->ray[i].next_vert_x;
                data->ray[i].hit_y_v = data->ray[i].next_vert_y;
				if(index == 2)
					data->ray[i].found_door = 1;
		        return 1;
        }
        else
        {
			// if(to_door(data,data->ray[i].next_vert_x,data->ray[i].next_vert_y))
            // {
            //     data->ray[i].hit_x_h = data->ray[i].next_vert_x;
            //     data->ray[i].hit_y_h = data->ray[i].next_vert_y;
            //     data->ray[i].found_door = 1;
            //     return 1;
            // }
            data->ray[i].next_vert_x += data->ray[i].x_step;
            data->ray[i].next_vert_y += data->ray[i].y_step;
        }
    }
	return 0;
}

void		door_coordinates(t_data *data)
{
	int i = 0;
	int j = 0;
	while(i < data->rows)
	{
		j = 0;
		while(j < data->cols)
		{
			if(data->grid[i][j] == 6)
			{
				data->x_door = j;
				data->y_door = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void	filler(t_data *data)
{
	int i = 0;
	int j = 0;
	while(i < data->rows)
	{
		j = 0;
		while(j < data->cols)
		{
			if(data->grid[i][j] == 6)
				data->grid[i][j] = 1;
			j++;
		}
		i++;
	}
}

void    cast_ray(t_data *data, int i)
{
    data->ray[i].ray_angle = adjust_angle(data->ray[i].ray_angle);
	data->ray[i].vert = 0;
	door_coordinates(data);
	filler(data);
	int h = horizontal_intersection(data, i);
	int v = vertical_intersection(data, i);
	dist_calc(data, i, h, v);
    return;
}

void dist_calc(t_data *data, int i, int h, int v)
{
	
	data->ray[i].dh = distance_between_xy(data, data->ray[i].hit_x_h, data->ray[i].hit_y_h);
	data->ray[i].dv = distance_between_xy(data, data->ray[i].hit_x_v, data->ray[i].hit_y_v);

    if (h == 0)
	{
		data->ray[i].hit_x = data->ray[i].hit_x_v;
        data->ray[i].hit_y = data->ray[i].hit_y_v;
        data->ray[i].ray_distance = data->ray[i].dv;
		data->ray[i].vert = 1;
		return;
	}
	if (data->ray[i].dh < data->ray[i].dv || (v == 0))
	{
        data->ray[i].hit_x = data->ray[i].hit_x_h;
        data->ray[i].hit_y = data->ray[i].hit_y_h;
        data->ray[i].ray_distance = data->ray[i].dh;
		return;
    }
	else 
	{
		data->ray[i].hit_x = data->ray[i].hit_x_v;
		data->ray[i].hit_y = data->ray[i].hit_y_v;
		data->ray[i].ray_distance = data->ray[i].dv;
		data->ray[i].vert = 1;
		return;
	}
}

double	distance_between_xy(t_data *data, double hit_x, double hit_y)
{
    double distance;
    distance = sqrt((hit_x - data->player.x)*(hit_x - data->player.x) + \
      (hit_y - data->player.y)*(hit_y - data->player.y));
    return (distance);
}