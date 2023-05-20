/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:13:46 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/20 05:41:38 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void wall_strip_draw(t_data *data, int i)
{
    for (int x = i; x < (i + 1) * WALL_STRIP_WIDTH; x++) {
        for (int y = data->wall.strip_top; y < data->wall.strip_bottom; y++) {
            my_mlx_pixel_put(&data->img, x, y, WHITE_COLOR);
        }
    }
}

void render_walls(t_data *data)
{
	int i;
	float perp_distance;

	i = -1;
	while (++i < NBR_RAYS)
	{
		perp_distance = data->ray[i].ray_distance * cos(data->ray[i].ray_angle - data->player.rotationAngle);
		// player->wall.proj = (WINDOW_WIDTH / 2) / tan(FOV / 2);
		data->wall.wall_height = (PIXEL / perp_distance) * data->wall.proj;

		data->wall.strip_top = (WINDOW_HEIGHT  - data->wall.wall_height) / 2;
		if (data->wall.strip_top < 0)
			data->wall.strip_top = 0;
		data->wall.strip_bottom = (WINDOW_HEIGHT  + data->wall.wall_height) / 2;
		if (data->wall.strip_bottom > WINDOW_HEIGHT)
			data->wall.strip_bottom = WINDOW_HEIGHT;
		
		wall_strip_draw(data, i);
	}
}

// void render_walls(t_data *data)
// {
// 	int i;
	
// 	i = -1;
// 	while (++i < NBR_RAYS)
// 	{
// 		data->wall.perp_distance = data->ray[i].ray_distance * cos(data->ray[i].ray_angle - data->player.rotationAngle);
// 		data->wall.proj = (WINDOW_WIDTH / 2) / tan(FOV / 2);
// 		data->wall.wall_height = (PIXEL / data->wall.perp_distance) * data->wall.proj;
// 		int strip_height = (int)data->wall.wall_height;
// 		data->wall.strip_top = (WINDOW_HEIGHT / 2) - (data->wall.wall_height / 2);
// 		data->wall.strip_top = data->wall.strip_top < 0 ? 0 : data->wall.strip_top;
// 		data->wall.strip_bottom = (WINDOW_HEIGHT / 2) + (strip_height / 2);
// 		data->wall.strip_bottom = data->wall.strip_bottom > WINDOW_HEIGHT ? WINDOW_HEIGHT : data->wall.strip_bottom;
// 		for (int x = data->wall.strip_top; x < data->wall.strip_bottom; x++)
// 			my_mlx_pixel_put(&data->img, i, x, WHITE_COLOR);
// 	}
// }