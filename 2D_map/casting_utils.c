/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/18 05:55:07 by zanejar          ###   ########.fr       */
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

int found_Wall(int x, int y, t_player *player)
{
    int my_x;
    int my_y;
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
            return 1;
    }
    my_x = floor(x / PIXEL);
    my_y = floor(y / PIXEL);
    if(player->grid[my_y][my_x] == 1)
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

void   horizontal_intersection(t_player*   player, float my_angle)
{
    player->ray.y_intercept = floor(player->y / PIXEL) * PIXEL;
    if(is_ray_facing_down(my_angle))
        player->ray.y_intercept += PIXEL;
	
    player->ray.x_intercept = player->x + (player->ray.y_intercept - player->y) / tan(my_angle);
    
	player->ray.y_step = PIXEL;
    if(!is_ray_facing_down(my_angle))
        player->ray.y_step *= -1;
    
	player->ray.x_step  = PIXEL / tan(my_angle);
    if(player->ray.x_step > 0  && !is_ray_facing_right(my_angle))
        player->ray.x_step *= -1;
	if(player->ray.x_step < 0 && is_ray_facing_right(my_angle))
		player->ray.x_step *= -1;
    
	player->ray.next_x = player->ray.x_intercept ;
    player->ray.next_y = player->ray.y_intercept ;
	
	if (!is_ray_facing_down(my_angle))
		player->ray.next_y--;
    
	while(player->ray.next_x >= 0 &&  player->ray.next_x <= WINDOW_WIDTH \
	&& player->ray.next_y >=0 && player->ray.next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(player->ray.next_x,player->ray.next_y,player))
        {
                player->hit.hit_x_h = player->ray.next_x;
                player->hit.hit_y_h = player->ray.next_y;
                // line_drawing(player, player->hit.hit_x_h, player->hit.hit_y_h);
                break;
        }
        else
        {
            player->ray.next_x += player->ray.x_step;
            player->ray.next_y += player->ray.y_step;
        }
    }
}

void   vertical_intersection(t_player*   player, float my_angle)
{
	player->ray.x_intercept = floor(player->x/PIXEL) * PIXEL;
	if(is_ray_facing_right(my_angle))
        player->ray.x_intercept += PIXEL;
    
	player->ray.y_intercept = player->y + (player->ray.x_intercept - player->x) * tan(my_angle);
    
	player->ray.x_step = PIXEL;
	if(!is_ray_facing_right(my_angle))
        player->ray.x_step *= -1;
    
	player->ray.y_step  = PIXEL * tan(my_angle);
    if(player->ray.y_step > 0  && !is_ray_facing_down(my_angle))
        player->ray.y_step *= -1;
	else if(player->ray.y_step < 0 && is_ray_facing_down(my_angle))
		player->ray.y_step *= -1;
    
	player->ray.next_x = player->ray.x_intercept ;
    player->ray.next_y = player->ray.y_intercept ;
	
	if (!is_ray_facing_right(my_angle))
		player->ray.next_x--;
    while(player->ray.next_x >= 0 && player->ray.next_x <= WINDOW_WIDTH && \
	player->ray.next_y >=0 && player->ray.next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(player->ray.next_x,player->ray.next_y,player))
        {
                player->hit.hit_x_v = player->ray.next_x;
                player->hit.hit_y_v = player->ray.next_y;
                // line_drawing(player, player->hit.hit_x_v, player->hit.hit_y_v);
                break;
        }
        else
        {
            player->ray.next_x += player->ray.x_step;
            player->ray.next_y += player->ray.y_step;
        }
    }
}

void    cast_ray(t_player*  player,float my_angle)
{
    my_angle = adjust_angle(my_angle);
	horizontal_intersection(player, my_angle);
	vertical_intersection(player, my_angle);
	dist_cacl(player);
    line_drawing(player, player->hit.hit_x, player->hit.hit_y);
    return;
}

void dist_cacl(t_player*  player)
{
	player->hit.dh = distance_between_xy(player, &player->hit.hit_x_h, &player->hit.hit_y_h);
	player->hit.dv = distance_between_xy(player, &player->hit.hit_x_v, &player->hit.hit_y_v);
    if(player->hit.dh < player->hit.dv)
	{
        player->hit.hit_x = player->hit.hit_x_h;
        player->hit.hit_y = player->hit.hit_y_h;
        player->hit_distance = player->hit.dh;
    }
    else
    {
        player->hit.hit_x = player->hit.hit_x_v;
        player->hit.hit_y = player->hit.hit_y_v;
        player->hit_distance = player->hit.dv;
    }
}

float	distance_between_xy(t_player* player,float *hit_x, float *hit_y)
{
    float distance;
    distance = sqrt((*hit_x - player->x)*(*hit_x - player->x) + \
      (*hit_y - player->y)*(*hit_y - player->y));
    return (distance);
}