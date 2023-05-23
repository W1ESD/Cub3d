/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:13:46 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/23 08:40:43 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
        
void render_walls(t_data *data, int i)
{
	for (int a = data->wall.strip_top; a < data->wall.strip_bottom; a++)
		my_mlx_pixel_put(&data->img, i, a, WHITE_COLOR);
}

void render_ceiling(t_data *data, int i)
{
	for (int y = 0; y < data->wall.strip_top; y++)
		my_mlx_pixel_put(&data->img, i, y, data->color_ceiling);
}

void render_floor(t_data *data, int i)
{
	for (int y = data->wall.strip_bottom; y < WINDOW_HEIGHT; y++)
		my_mlx_pixel_put(&data->img, i, y, data->color_floor);
}

void render_3d(t_data *data)
{
	int i;
	double perp_distance;

	i = -1;
	while (++i < NBR_RAYS)
	{
		perp_distance = data->ray[i].ray_distance * cos(data->ray[i].ray_angle - data->player.rotationAngle);
		data->wall.strip_height = (PIXEL / perp_distance) * data->wall.projection;

		data->wall.strip_top = (WINDOW_HEIGHT - data->wall.strip_height) / 2;
		if (data->wall.strip_top < 0)
			data->wall.strip_top = 0;
		data->wall.strip_bottom = (WINDOW_HEIGHT + data->wall.strip_height) / 2;
		if (data->wall.strip_bottom > WINDOW_HEIGHT)
			data->wall.strip_bottom = WINDOW_HEIGHT;
		render_walls(data, i);
		render_ceiling(data, i);
		render_floor(data, i);
	}
}
