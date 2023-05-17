/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/17 05:14:14 by zanejar          ###   ########.fr       */
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

void   horizontal_intersection(t_player*   player, double my_angle, int *hit_x, int *hit_y)
{
    player->ray.y_intercept = floor(player->y/PIXEL) * PIXEL;
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
                *hit_x = player->ray.next_x;
                *hit_y = player->ray.next_y;
                // line_drawing(player, *hit_x , *hit_y);
                break;
        }
        else
        {
            player->ray.next_x += player->ray.x_step;
            player->ray.next_y += player->ray.y_step;
        }
    }
}

void   vertical_intersection(t_player*   player, double my_angle, int *hit_x, int *hit_y)
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
                *hit_x = player->ray.next_x;
                *hit_y = player->ray.next_y;
                // line_drawing(player, *hit_x ,*hit_y);
                break;
        }
        else
        {
            player->ray.next_x += player->ray.x_step;
            player->ray.next_y += player->ray.y_step;
        }
    }
}

// void ray_direction(double my_angle,int *ray_direction_du,int *ray_direction_rf)
// {
// 	if (my_angle > 0 && my_angle < PI)
// 			*ray_direction_du = 1; //down
// 	else if( !(my_angle > 0 && my_angle < PI))
// 			*ray_direction_du = 2; //up
// 	if (my_angle < PI / 2 || my_angle > 3 * PI / 2)
// 			*ray_direction_rf = 1; //right
// 	else if(!(my_angle < PI / 2 || my_angle > 3 * PI / 2))
// 			*ray_direction_rf = 2; //left
// }

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

// void    cast_ray(t_player*  player,double my_angle)
// {
//     my_angle = adjust_angle(my_angle);
// 	horizontal_intersection(player, my_angle, &player->hit.hit_x_h, &player->hit.hit_y_h);
// 	vertical_intersection(player, my_angle, &player->hit.hit_x_v, &player->hit.hit_y_v);

// 	player->hit.dh = Distance_between_xy(player, &player->hit.hit_x_h, &player->hit.hit_y_h);
// 	player->hit.dv = Distance_between_xy(player, &player->hit.hit_x_v, &player->hit.hit_y_v);
//     if(player->hit.dh < player->hit.dv)
// 	{
//         player->hit.hit_x = player->hit.hit_x_h;
//         player->hit.hit_y = player->hit.hit_y_h;
//         player->hit_distance = player->hit.dh;
//     }
//     else
//     {
//         player->hit.hit_x = player->hit.hit_x_v;
//         player->hit.hit_y = player->hit.hit_y_v;
//         player->hit_distance = player->hit.dv;
//     }
//     line_drawing(player, player->hit.hit_x, player->hit.hit_y);
//     return;
// }

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

int	distance_between_xy(t_player* player,int *hit_x, int *hit_y)
{
    int distance;
    distance = sqrt((*hit_x - player->x)*(*hit_x - player->x) + \
      (*hit_y - player->y)*(*hit_y - player->y));
    return (distance);
}