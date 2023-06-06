/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_conds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:12:15 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 03:17:29 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cond1(t_data *data)
{
	if (able_to_walk_up(data) && really_able_up(data))
	{
		data->player.x += cos(data->player.rotation_angle)
			* data->player.move_speed;
		data->player.y += sin(data->player.rotation_angle)
			* data->player.move_speed;
	}
}

void	cond2(t_data *data)
{
	if (able_to_walk_down(data) && really_able_down(data))
	{
		data->player.x -= cos(data->player.rotation_angle)
			* data->player.move_speed;
		data->player.y -= sin(data->player.rotation_angle)
			* data->player.move_speed;
	}
}

void	cond3(t_data *data)
{
	if (able_to_turn_left(data) && really_able_left(data))
	{
		data->player.x += cos(data->player.rotation_angle + (PI / 2))
			* data->player.move_speed;
		data->player.y += sin(data->player.rotation_angle + (PI / 2))
			* data->player.move_speed;
	}
}

void	cond4(t_data *data)
{
	if (able_to_turn_right(data) && really_able_right(data))
	{
		data->player.x -= cos(data->player.rotation_angle + (PI / 2))
			* data->player.move_speed;
		data->player.y -= sin(data->player.rotation_angle + (PI / 2))
			* data->player.move_speed;
	}
}
