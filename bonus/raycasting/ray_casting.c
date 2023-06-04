/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:26 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 20:37:14 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
  
void	 line_drawing(t_data *data,  int end_x, int end_y)
{   
	int	pixels_color = WHITE_COLOR;

	double distance_x = end_x - data->player.x;
	
	double distance_y = end_y - data->player.y;

	int pixels = sqrt((distance_x * distance_x) + (distance_y * distance_y));

	distance_x /= pixels;
	 
	distance_y /= pixels;   

	double pixel_x = data->player.x;
	
	double pixel_y = data->player.y; 
 
    while (pixels > 0)
    {
        my_mlx_pixel_put(&data->img, pixel_x * MINI_MAP_SCALE_FACTOR,\
		pixel_y * MINI_MAP_SCALE_FACTOR, pixels_color);
        pixel_x += distance_x;
        pixel_y += distance_y;
        pixels--;
    }
}
       
void	ray_caster(t_data *data)
{
	data->wall.projection = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	int i = 0;

	data->ray[i].ray_angle = data->player.rotationAngle - (FOV / 2);
	while(i < NBR_RAYS)
	{
		data->ray[i].found_door = 0;
		
		cast_ray(data, i);
		// line_drawing(data,data->ray[i].hit_x,data->ray[i].hit_y);
		if (i + 1 < NBR_RAYS)
			data->ray[i + 1].ray_angle = data->player.rotationAngle + (atan((i - (NBR_RAYS / 2)) / data->wall.projection));
		i++;
	}
}