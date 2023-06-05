/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 05:34:45 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/05 21:04:15 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wall_col_ray_h(t_data *data, int index, int i)
{
	data->ray[i].hit_x_h = data->ray[i].next_horz_x;
	data->ray[i].hit_y_h = data->ray[i].next_horz_y;
	if (index == 2)
		data->ray[i].hit_door_horizontal = 1;
}

void	wall_col_ray_v(t_data *data, int index, int i)
{
	data->ray[i].hit_x_v = data->ray[i].next_vert_x;
	data->ray[i].hit_y_v = data->ray[i].next_vert_y;
	if (index == 2)
		data->ray[i].hit_door_vertical = 1;
}

void	set_hit1(t_data *data, int i)
{
	if (data->ray[i].hit_door_vertical == 1)
		data->ray[i].found_door = 1;
	data->ray[i].hit_x = data->ray[i].hit_x_v;
	data->ray[i].hit_y = data->ray[i].hit_y_v;
	data->ray[i].ray_distance = data->ray[i].dv;
	data->ray[i].vert = 1;
	return ;
}

void	set_hit2(t_data *data, int i)
{
	if (data->ray[i].hit_door_horizontal == 1)
		data->ray[i].found_door = 1;
	data->ray[i].hit_x = data->ray[i].hit_x_h;
	data->ray[i].hit_y = data->ray[i].hit_y_h;
	data->ray[i].ray_distance = data->ray[i].dh;
	return ;
}

void	set_hit3(t_data *data, int i)
{
	if (data->ray[i].hit_door_vertical == 1)
		data->ray[i].found_door = 1;
	data->ray[i].hit_x = data->ray[i].hit_x_v;
	data->ray[i].hit_y = data->ray[i].hit_y_v;
	data->ray[i].ray_distance = data->ray[i].dv;
	data->ray[i].vert = 1;
	return ;
}
