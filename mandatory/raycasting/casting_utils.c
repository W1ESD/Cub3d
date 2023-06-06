/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:36 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/06 04:28:18 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	horizontal_intersection(t_data *data, int i)
{
	get_hor(data, i);
	while (data->ray[i].next_horz_x >= 0
		&& data->ray[i].next_horz_x <= WINDOW_WIDTH
		&& data->ray[i].next_horz_y >= 0
		&& data->ray[i].next_horz_y <= WINDOW_HEIGHT)
	{
		if (found_wall(data, data->ray[i].next_horz_x,
				data->ray[i].next_horz_y))
		{
			data->ray[i].hit_x_h = data->ray[i].next_horz_x;
			data->ray[i].hit_y_h = data->ray[i].next_horz_y;
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

int	vertical_intersection(t_data *data, int i)
{
	get_vert(data, i);
	while (data->ray[i].next_vert_x >= 0
		&& data->ray[i].next_vert_x <= WINDOW_WIDTH
		&& data->ray[i].next_vert_y >= 0
		&& data->ray[i].next_vert_y <= WINDOW_HEIGHT)
	{
		if (found_wall(data, data->ray[i].next_vert_x,
				data->ray[i].next_vert_y))
		{
			data->ray[i].hit_x_v = data->ray[i].next_vert_x;
			data->ray[i].hit_y_v = data->ray[i].next_vert_y;
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
	h = horizontal_intersection(data, i);
	v = vertical_intersection(data, i);
	dist_calc(data, i, h, v);
	return ;
}

void	dist_calc(t_data *data, int i, int h, int v)
{
	data->ray[i].dh = distance_between_xy(data, data->ray[i].hit_x_h,
			data->ray[i].hit_y_h);
	data->ray[i].dv = distance_between_xy(data, data->ray[i].hit_x_v,
			data->ray[i].hit_y_v);
	if (h == 0)
		return (first_calcul(data, i));
	if (data->ray[i].dh < data->ray[i].dv || (v == 0))
		return (second_calcul(data, i));
	else
		return (last_calcul(data, i));
}

double	distance_between_xy(t_data *data, double hit_x, double hit_y)
{
	double	distance;

	distance = sqrt((hit_x - data->player.x) * (hit_x - data->player.x) + (hit_y
				- data->player.y) * (hit_y - data->player.y));
	return (distance);
}
