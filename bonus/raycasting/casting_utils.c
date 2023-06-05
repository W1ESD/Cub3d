/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/05 21:23:40 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	first_h_intersection(t_data *data, int i)
{
	data->ray[i].y_intercept = floor(data->player.y / data->tile_size)
		* data->tile_size;
	if (is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].y_intercept += data->tile_size;
	data->ray[i].x_intercept = data->player.x + (data->ray[i].y_intercept
			- data->player.y) / tan(data->ray[i].ray_angle);
	data->ray[i].y_step = data->tile_size;
	if (!is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].y_step *= -1;
	data->ray[i].x_step = data->tile_size / tan(data->ray[i].ray_angle);
	if (data->ray[i].x_step > 0 && !is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].x_step *= -1;
	if (data->ray[i].x_step < 0 && is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].x_step *= -1;
	data->ray[i].next_horz_x = data->ray[i].x_intercept;
	data->ray[i].next_horz_y = data->ray[i].y_intercept;
	if (!is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].next_horz_y--;
}

int	horizontal_intersection(t_data *data, int i)
{
	int	index;

	index = 0;
	first_h_intersection(data, i);
	while (data->ray[i].next_horz_x >= 0
		&& data->ray[i].next_horz_x <= WINDOW_WIDTH
		&& data->ray[i].next_horz_y >= 0
		&& data->ray[i].next_horz_y <= WINDOW_HEIGHT)
	{
		index = found_wall(data, data->ray[i].next_horz_x,
				data->ray[i].next_horz_y);
		if (index)
		{
			wall_col_ray_h(data, index, i);
			return (1);
		}
		else
		{
			data->ray[i].next_horz_x += data->ray[i].x_step;
			data->ray[i].next_horz_y += data->ray[i].y_step;
		}
	}
	return (0);
}

void	first_v_intersection(t_data *data, int i)
{
	data->ray[i].x_intercept = floor(data->player.x / data->tile_size)
		* data->tile_size;
	if (is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].x_intercept += data->tile_size;
	data->ray[i].y_intercept = data->player.y + (data->ray[i].x_intercept
			- data->player.x) * tan(data->ray[i].ray_angle);
	data->ray[i].x_step = data->tile_size;
	if (!is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].x_step *= -1;
	data->ray[i].y_step = data->tile_size * tan(data->ray[i].ray_angle);
	if (data->ray[i].y_step > 0 && !is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].y_step *= -1;
	else if (data->ray[i].y_step < 0
		&& is_ray_facing_down(data->ray[i].ray_angle))
		data->ray[i].y_step *= -1;
	data->ray[i].next_vert_x = data->ray[i].x_intercept;
	data->ray[i].next_vert_y = data->ray[i].y_intercept;
	if (!is_ray_facing_right(data->ray[i].ray_angle))
		data->ray[i].next_vert_x--;
}

int	vertical_intersection(t_data *data, int i)
{
	int	index;

	index = 0;
	first_v_intersection(data, i);
	while (data->ray[i].next_vert_x >= 0
		&& data->ray[i].next_vert_x <= WINDOW_WIDTH
		&& data->ray[i].next_vert_y >= 0
		&& data->ray[i].next_vert_y <= WINDOW_HEIGHT)
	{
		index = found_wall(data, data->ray[i].next_vert_x,
				data->ray[i].next_vert_y);
		if (index)
		{
			wall_col_ray_v(data, index, i);
			return (1);
		}
		else
		{
			data->ray[i].next_vert_x += data->ray[i].x_step;
			data->ray[i].next_vert_y += data->ray[i].y_step;
		}
	}
	return (0);
}

void	cast_ray(t_data *data, int i)
{
	int	h;
	int	v;

	data->ray[i].ray_angle = adjust_angle(data->ray[i].ray_angle);
	data->ray[i].vert = 0;
	data->ray[i].hit_door_vertical = 0;
	data->ray[i].hit_door_horizontal = 0;
	data->ray[i].found_door = 0;
	h = horizontal_intersection(data, i);
	v = vertical_intersection(data, i);
	dist_calc(data, i, h, v);
	return ;
}
