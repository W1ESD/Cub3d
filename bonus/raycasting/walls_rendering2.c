/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:35:45 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 04:02:28 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_loop(t_data *data, float x, float y, int i)
{
	int	a;

	a = data->wall.strip_top;
	while (a < data->wall.strip_bottom)
	{
		if (data->ray[i].found_door)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[4], x,
					y));
		else if (data->wall_side == NORTH)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[0], x,
					y));
		else if (data->wall_side == SOUTH)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[1], x,
					y));
		else if (data->wall_side == EAST)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[2], x,
					y));
		else if (data->wall_side == WEST)
			my_mlx_pixel_put(&data->img, i, a, get_color(&data->texture[3], x,
					y));
		y += TEX_SIZE / data->wall.strip_height;
		a++;
	}
}

void	render_walls(t_data *data, int i)
{
	float	x;
	float	y;
	float	tex_ratio;
	int		pos_y;

	if (data->ray[i].vert)
		x = (int)data->ray[i].hit_y % (int)(data->tile_size);
	else
		x = (int)data->ray[i].hit_x % (int)data->tile_size;
	tex_ratio = TEX_SIZE / data->tile_size;
	x *= tex_ratio;
	if (data->wall.strip_top > 0)
		y = 0;
	else
	{
		pos_y = (data->wall.strip_height - WINDOW_HEIGHT) / 2;
		y = pos_y * (TEX_SIZE / data->wall.strip_height);
	}
	render_loop(data, x, y, i);
}
