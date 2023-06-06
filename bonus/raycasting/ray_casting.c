/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:26 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/06 01:50:10 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	line_drawing(t_data *data, int end_x, int end_y)
{
	t_vars	vars;

	vars.pixels_color = RED_COLOR;
	vars.distance_x = end_x - data->player.x;
	vars.distance_y = end_y - data->player.y;
	vars.pixels = sqrt((vars.distance_x * vars.distance_x) + \
	(vars.distance_y * vars.distance_y));
	vars.distance_x /= vars.pixels;
	vars.distance_y /= vars.pixels;
	vars.pixel_x = data->player.x;
	vars.pixel_y = data->player.y;
	while (vars.pixels > 0)
	{
		my_mlx_pixel_put(&data->img, vars.pixel_x * \
		MINI_MAP_SCALE_FACTOR, vars.pixel_y * \
		MINI_MAP_SCALE_FACTOR, vars.pixels_color);
		vars.pixel_x += vars.distance_x;
		vars.pixel_y += vars.distance_y;
		vars.pixels--;
	}
}

void	ray_caster(t_data *data)
{
	float	fov;
	int		i;

	fov = 60 * (M_PI / 180);
	data->wall.projection = (WINDOW_WIDTH / 2) / tan(fov / 2);
	i = 0;
	data->ray[i].ray_angle = data->player.rotation_angle - (fov / 2);
	while (i < NBR_RAYS)
	{
		cast_ray(data, i);
		if (i + 1 < NBR_RAYS)
		{	
			data->ray[i + 1].ray_angle = data->player.rotation_angle + \
			(atan((i - (NBR_RAYS / 2)) / data->wall.projection));
		}
		i++;
	}
}
