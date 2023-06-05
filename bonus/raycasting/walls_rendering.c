/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:13:46 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 03:59:17 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wall_sider(t_data *data, int i)
{
	if (data->ray[i].found_door)
		data->wall_side = DOOR;
	else if (!is_ray_facing_down(data->ray[i].ray_angle) && !data->ray[i].vert)
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
	int		k;

	dst = (char *)data->addr + (y * data->line_length + x \
	* (data->bits_per_pixel / 8));
	k = *(unsigned int *)dst;
	return (k);
}

void	render_ceiling(t_data *data, int i)
{
	int	y;

	y = 0;
	while (y < data->wall.strip_top)
	{
		my_mlx_pixel_put(&data->img, i, y, data->color_ceiling);
		y++;
	}
}

void	render_floor(t_data *data, int i)
{
	int	y;

	y = data->wall.strip_bottom;
	while (y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put(&data->img, i, y, data->color_floor);
		y++;
	}
}

void	render_3d(t_data *data)
{
	int		i;
	double	perp_distance;

	i = -1;
	while (++i < NBR_RAYS)
	{
		perp_distance = data->ray[i].ray_distance * cos(data->ray[i].ray_angle \
		- data->player.rotation_angle);
		data->wall.strip_height = (data->tile_size / perp_distance)
			* data->wall.projection;
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
