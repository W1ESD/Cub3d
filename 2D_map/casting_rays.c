/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/16 23:48:00 by zanejar          ###   ########.fr       */
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

int found_Wall(long x,long y,t_player *player)
{
    long my_x;
    long my_y;
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
            return 1;
     }
    my_x = floor(x / PIXEL);
    my_y = floor(y / PIXEL);
    if(player->grid[my_y][my_x] == 1)
    	return 1;
    return 0;
}

void   horizontal_intersection(t_player*   player,double my_angle, \
int ray_direction_du,int ray_direction_rf,int *hitx,int *hity)
{
    long        x_intercept;
    long        y_intercept;
    long        x_step;
    long        y_step;
    long        next_x;
    long        next_y;

    y_intercept = floor(player->y/PIXEL) * PIXEL;
    if(ray_direction_du == 1)
        y_intercept += PIXEL;
    x_intercept = player->x + (y_intercept - player->y) / tan(my_angle);
    y_step = PIXEL;
    if(ray_direction_du == 2)
        y_step *= -1;
    x_step  = PIXEL/tan(my_angle);
    if(x_step > 0  && ray_direction_rf == 2)
        x_step *= -1;
	if(x_step < 0 && ray_direction_rf == 1)
		x_step *= -1;
    next_x = x_intercept ;
    next_y = y_intercept ;
	
	if (ray_direction_du == 2)
		next_y--;
    while(next_x >= 0 &&  next_x <= WINDOW_WIDTH && next_y >=0 && next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(next_x,next_y,player))
        {
                *hitx = next_x;
                *hity = next_y;
                // line_drawing(player, *hitx , *hity);
                break;
        }
        else
        {
            next_x += x_step;
            next_y += y_step;
        }
    }
}

void   vertical_intersection(t_player*   player,double my_angle,\
int ray_direction_du,int ray_direction_rf,int *hitx,int *hity)
{
	long        x_intercept;
    long        y_intercept;
    long        x_step;
    long        y_step;
    long        next_x;
    long        next_y;

    x_intercept = floor(player->x/PIXEL) * PIXEL;
	if(ray_direction_rf == 1)
        x_intercept += PIXEL;
    
	y_intercept = player->y + (x_intercept - player->x) * tan(my_angle);
    
	x_step = PIXEL;   
	if(ray_direction_rf == 2)
        x_step *= -1;
    
	y_step  = PIXEL * tan(my_angle);
    if(y_step > 0  && ray_direction_du == 2)
        y_step *= -1;
	else if(y_step < 0 && ray_direction_du == 1)
		y_step *= -1;
    
	next_x = x_intercept ;
    next_y = y_intercept ;
	
	if (ray_direction_rf == 2)
		next_x--;
    while(next_x >= 0 && next_x <= WINDOW_WIDTH && next_y >=0 && next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(next_x,next_y,player))
        {
                *hitx = next_x;
                *hity = next_y;
                // line_drawing(player, *hitx ,*hity);
                break;
        }
        else
        {
            next_x += x_step;
            next_y += y_step;
        }
    }
}

void ray_direction(double my_angle,int *ray_direction_du,int *ray_direction_rf)
{
	if (my_angle > 0 && my_angle < PI)
			*ray_direction_du = 1; //down
	else if( !(my_angle > 0 && my_angle < PI))
			*ray_direction_du = 2; //up
	if (my_angle < PI / 2 || my_angle > 3 * PI / 2)
			*ray_direction_rf = 1; //right
	else if(!(my_angle < PI / 2 || my_angle > 3 * PI / 2))
			*ray_direction_rf = 2; //left
}

void    cast_ray(t_player*  player,double my_angle)
{
    int     hit_wally_v = 0; // position x when the ray was casted
    int     hit_wallx_v = 0; // position y when the ray was casted
    int     hit_wally_h = 0; 
    int     hit_wallx_h = 0;
    int     wall_hit_x=0;
    int     wall_hit_y=0;
    
    double    distance_hit = 0; //distance between the player and the colision 
    double dh=1000000;
    double dv=1000000;
    
    (void)distance_hit;
    int     ray_direction_du = 0;
    int     ray_direction_rf = 0;

    my_angle = adjust_angle(my_angle);
	ray_direction(my_angle,&ray_direction_du,&ray_direction_rf);
	
	horizontal_intersection(player,my_angle,ray_direction_du,ray_direction_rf,&hit_wallx_h,&hit_wally_h);
	vertical_intersection(player,my_angle,ray_direction_du,ray_direction_rf,&hit_wallx_v,&hit_wally_v);
    // calculate distances then choose the smullest value ;
	dh = Distance_between_xy(player,&hit_wallx_h,&hit_wally_h);
	dv = Distance_between_xy(player,&hit_wallx_v,&hit_wally_v);
    if(dh < dv){
        wall_hit_x = hit_wallx_h;
        wall_hit_y = hit_wally_h;
        distance_hit =  dh;
    }
    else
    {
        wall_hit_x = hit_wallx_v;
        wall_hit_y = hit_wally_v;
        distance_hit = dv;
    }
    line_drawing(player,wall_hit_x,wall_hit_y);
    return;

}
double     Distance_between_xy(t_player* player,int    *hit_x,int      *hit_y)
{
    double distance;
    distance = sqrt((*hit_x - player->x)*(*hit_x - player->x) + \
      (*hit_y - player->y)*(*hit_y - player->y));
    return (distance);
}