/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/16 18:49:12 by zanejar          ###   ########.fr       */
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
    {
        // printf("{%ld -- %ld}",my_x ,my_y);
        return 1;
    }
    return 0;
}

int   horizontal_intersection(t_player*   player,double my_angle,\
int ray_direction_du,int ray_direction_rf,int hitx,int hity)
{
    long        x_intercept;
    long        y_intercept;
    long        x_step;
    long        y_step;
    long        next_x;
    long        next_y;
    int         found;
    
    found = 0;

    //first of all when need to find the closest intersection with the horizontel line (x_intercept)&(y_intercept);
    //find the y-cordonate of the nearest horiz
    y_intercept = floor(player->y/PIXEL) * PIXEL;
    if(ray_direction_du == 1)
        y_intercept += PIXEL;
    //find the x-cordonate d a9rab horizontal
    x_intercept = player->x + (y_intercept - player->y)/tan(my_angle);
    // printf("|%ld|\n",x_intercept);
    //x_step && y_step calculation
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
    while(next_x >= 0 && next_x <= WINDOW_WIDTH && next_y >=0 && next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(next_x,next_y,player))
        {
                //we found a wall hit;
                found = 1;
                hitx = next_x;
                hity = next_y;
                line_drawing(player, hitx ,hity);
                break;
        }
        else
        {
            next_x += x_step;
            next_y += y_step;
        }
    }
    return 1;
}

int   vertical_intersection(t_player*   player,double my_angle,\
int ray_direction_du,int ray_direction_rf,int hitx,int hity)
{
	 long        x_intercept;
    long        y_intercept;
    long        x_step;
    long        y_step;
    long        next_x;
    long        next_y;
    int         found; 
    found = 0;

    x_intercept = floor(player->x/PIXEL) * PIXEL;
    if(ray_direction_rf == 1)
        x_intercept += PIXEL;
    y_intercept = player->y + (x_intercept - player->x)/tan(my_angle);
    x_step = PIXEL;
    if(ray_direction_rf == 2)
        x_step *= -1;
    y_step  = PIXEL * tan(my_angle);
    if(y_step > 0  && ray_direction_du == 2)
        y_step *= -1;
	if(y_step < 0 && ray_direction_du == 1)
		y_step *= -1;
    next_x = x_intercept ;
    next_y = y_intercept ;
	
	if (ray_direction_rf == 2)
		next_x--;
    while(next_x >= 0 && next_x <= WINDOW_WIDTH && next_y >=0 && next_y <= WINDOW_HEIGHT )
    {
        if(found_Wall(next_x,next_y,player))
        {
                found = 1;
                hitx = next_x;
                hity = next_y;
                line_drawing(player, hitx ,hity);
                break;
        }
        else
        {
            next_x += x_step;
            next_y += y_step;
        }
    }
    return 1;
}


void    cast_ray(t_player*  player,double my_angle)
{
    int     hit_wallx = 0; // position x when the ray was casted
    int     hit_wally = 0; // position y when the ray was casted
    double    distance_hit = 0; //distance between the player and the colision 
    
    (void)distance_hit;
    int     ray_direction_du = 0;
    int     ray_direction_rf = 0;

    my_angle = adjust_angle(my_angle);

    if(my_angle > 0 && my_angle < PI)
            ray_direction_du = 1;//down
    else
        if(!(my_angle > 0 && my_angle < PI))
            ray_direction_du = 2;//up
    if(my_angle < PI / 2 || my_angle > 3 * PI / 2)
            ray_direction_rf = 1;//right
    else
        if(!(my_angle < PI / 2 || my_angle > 3 * PI / 2))
            ray_direction_rf = 2;//left
	 horizontal_intersection(player,my_angle,ray_direction_du,ray_direction_rf,hit_wallx,hit_wally);
	//vertical_intersection(player,my_angle,ray_direction_du,ray_direction_rf,hit_wallx,hit_wally);
    return;

}