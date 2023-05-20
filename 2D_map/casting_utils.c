/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/20 05:16:53 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float adjust_angle(float angle) 
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
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
            return 1;
    }
    my_x = floor(x / PIXEL);
    my_y = floor(y / PIXEL);
    if(data->grid[my_y][my_x] == 1)
    	return 1;
    return 0;
}

int is_ray_facing_down(float my_angle)
{
	if (my_angle > 0 && my_angle < PI)
		return 1;
	return 0;
}

int is_ray_facing_right(float my_angle)
{
	if (my_angle < PI / 2 || my_angle > 3 * PI / 2)
		return 1;
	return 0;
}

void   horizontal_intersection(t_data *data, int i)
{
    data->ray[i].y_intercept = floor(data->player.y / PIXEL) * PIXEL;
    if(is_ray_facing_down(data->ray[i].ray_angle))
        data->ray[i].y_intercept += PIXEL;
	
    data->ray[i].x_intercept = data->player.x + (data->ray[i].y_intercept - data->player.y) / tan(data->ray[i].ray_angle);
    
	data->ray[i].y_step = PIXEL;
    if(!is_ray_facing_down(data->ray[i].ray_angle))
        data->ray[i].y_step *= -1;
    
	data->ray[i].x_step  = PIXEL / tan(data->ray[i].ray_angle);
    if(data->ray[i].x_step > 0  && !is_ray_facing_right(data->ray[i].ray_angle))
        data->ray[i].x_step *= -1;
	if(data->ray[i].x_step < 0 && is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].x_step *= -1;
    
	data->ray[i].next_x = data->ray[i].x_intercept ;
    data->ray[i].next_y = data->ray[i].y_intercept ;
	
	if (!is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].next_y--;
	
	while(data->ray[i].next_x >= 0 &&  data->ray[i].next_x <= WINDOW_WIDTH \
	&& data->ray[i].next_y >=0 && data->ray[i].next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(data, data->ray[i].next_x,data->ray[i].next_y))
        {
                data->hit.hit_x_h = data->ray[i].next_x;
                data->hit.hit_y_h = data->ray[i].next_y;
                // line_drawing(data, data->hit.hit_x_h, data->hit.hit_y_h);
                break;
        }
        else
        {
            data->ray[i].next_x += data->ray[i].x_step;
            data->ray[i].next_y += data->ray[i].y_step;
        }
	}
}

void   vertical_intersection(t_data *data, int i)
{
	data->ray[i].x_intercept = floor(data->player.x/PIXEL) * PIXEL;
	if(is_ray_facing_right(data->ray[i].ray_angle))
        data->ray[i].x_intercept += PIXEL;
    
	data->ray[i].y_intercept = data->player.y + (data->ray[i].x_intercept - data->player.x) * tan(data->ray[i].ray_angle);
    
	data->ray[i].x_step = PIXEL;
	if(!is_ray_facing_right(data->ray[i].ray_angle))
        data->ray[i].x_step *= -1;
    
	data->ray[i].y_step  = PIXEL * tan(data->ray[i].ray_angle);
    if(data->ray[i].y_step > 0  && !is_ray_facing_down(data->ray[i].ray_angle))
        data->ray[i].y_step *= -1;
	else if(data->ray[i].y_step < 0 && is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].y_step *= -1;
    
	data->ray[i].next_x = data->ray[i].x_intercept ;
    data->ray[i].next_y = data->ray[i].y_intercept ;
	
	if (!is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].next_x--;
    while(data->ray[i].next_x >= 0 && data->ray[i].next_x <= WINDOW_WIDTH && \
	data->ray[i].next_y >=0 && data->ray[i].next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(data, data->ray[i].next_x, data->ray[i].next_y))
        {
                data->hit.hit_x_v = data->ray[i].next_x;
                data->hit.hit_y_v = data->ray[i].next_y;
                // line_drawing(data, data->hit.hit_x_v, data->hit.hit_y_v);
                break;
        }
        else
        {
            data->ray[i].next_x += data->ray[i].x_step;
            data->ray[i].next_y += data->ray[i].y_step;
        }
    }
}

void    cast_ray(t_data *data, int i)
{
    data->ray[i].ray_angle = adjust_angle(data->ray[i].ray_angle);
	horizontal_intersection(data, i);
	vertical_intersection(data, i);
	dist_calc(data, i);
    line_drawing(data, data->hit.hit_x, data->hit.hit_y);
    return;
}

void dist_calc(t_data *data, int i)
{
	data->hit.dh = distance_between_xy(data, &data->hit.hit_x_h, &data->hit.hit_y_h);
	data->hit.dv = distance_between_xy(data, &data->hit.hit_x_v, &data->hit.hit_y_v);
    if(data->hit.dh < data->hit.dv)
	{
        data->hit.hit_x = data->hit.hit_x_h;
        data->hit.hit_y = data->hit.hit_y_h;
        data->ray[i].ray_distance = data->hit.dh;
    }
    else
    {
        data->hit.hit_x = data->hit.hit_x_v;
        data->hit.hit_y = data->hit.hit_y_v;
        data->ray[i].ray_distance = data->hit.dv;
    }
}

float	distance_between_xy(t_data *data, float *hit_x, float *hit_y)
{
    float distance;
    distance = sqrt((*hit_x - data->player.x)*(*hit_x - data->player.x) + \
      (*hit_y - data->player.y)*(*hit_y - data->player.y));
    return (distance);
}