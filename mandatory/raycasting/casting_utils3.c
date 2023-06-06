/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:24:09 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 04:30:32 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_hor(t_data *data, int i)
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

void	get_vert(t_data *data, int i)
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

void	first_calcul(t_data *data, int i)
{
	data->ray[i].hit_x = data->ray[i].hit_x_v;
	data->ray[i].hit_y = data->ray[i].hit_y_v;
	data->ray[i].ray_distance = data->ray[i].dv;
	data->ray[i].vert = 1;
	return ;
}

void	second_calcul(t_data *data, int i)
{
	data->ray[i].hit_x = data->ray[i].hit_x_h;
	data->ray[i].hit_y = data->ray[i].hit_y_h;
	data->ray[i].ray_distance = data->ray[i].dh;
	return ;
}

void	last_calcul(t_data *data, int i)
{
	data->ray[i].hit_x = data->ray[i].hit_x_v;
	data->ray[i].hit_y = data->ray[i].hit_y_v;
	data->ray[i].ray_distance = data->ray[i].dv;
	data->ray[i].vert = 1;
	return ;
}
