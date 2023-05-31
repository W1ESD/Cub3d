/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:13:46 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/31 21:54:49 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void wall_sider(t_data *data, int i)
{
	if (!is_ray_facing_down(data->ray[i].ray_angle) && !data->ray[i].vert)
		data->wall_side = NORTH;
	else if (is_ray_facing_down(data->ray[i].ray_angle) && !data->ray[i].vert)
		data->wall_side = SOUTH;
	else if (is_ray_facing_right(data->ray[i].ray_angle) && data->ray[i].vert)
		data->wall_side = EAST;
	else if (!is_ray_facing_right(data->ray[i].ray_angle) && data->ray[i].vert)
		data->wall_side = WEST;
}

int	get_color(t_img *data, int x, int y)
{
	char	*dst;
	 
	dst = (char*) data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	int k = *(unsigned int*)dst;
	return (k);
}

void render_walls(t_data *data, int i)
{
	float x;
	float y;
	
	if (data->ray[i].vert)
		x = (int)data->ray[i].hit_y % PIXEL;
	else
		x = (int)data->ray[i].hit_x % PIXEL;
	if (data->wall.strip_top > 0)
		y = 0;
	else if (data->wall.strip_top == 0)
	{
		int pos_y = (data->wall.strip_height - WINDOW_HEIGHT) / 2;
		y = pos_y * (PIXEL / data->wall.strip_height);
	}
	for (int a = data->wall.strip_top; a < data->wall.strip_bottom; a++)
	{
		if (data->wall_side == NORTH)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[0], x, y));
		else if (data->wall_side == SOUTH)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[1], x, y));
		else if (data->wall_side == EAST)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[2], x, y));
		else if (data->wall_side == WEST)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[3], x, y));
		y += PIXEL / data->wall.strip_height;
	}
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
		wall_sider(data, i);
		render_walls(data, i);
		render_ceiling(data, i);
		render_floor(data, i);
	}
}
