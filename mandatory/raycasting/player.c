/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 04:03:44 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_player(t_data *data, t_data_parsing *parsing)
{
	data->player.x = (parsing->player_x) * data->tile_size;
	data->player.y = (parsing->player_y) * data->tile_size;
	data->player.width = 5;
	data->player.height = 5;
	data->player.side_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_angle = get_angle(parsing);
	data->player.move_speed = 2;
	data->player.rotation_speed = (3 * PI) / 100;
}

int	really_able_left(t_data *data)
{
	int	a;

	a = 0;
	a += wall_x_left(data);
	a += wall_y_left(data);
	if (a == 2 || a == 1)
		return (0);
	return (1);
}

int	really_able_up(t_data *data)
{
	int	a;

	a = 0;
	a += wall_x(data);
	a += wall_y(data);
	if (a == 2 || a == 1)
		return (0);
	return (1);
}

int	really_able_down(t_data *data)
{
	int	a;

	a = 0;
	a += wall_x_down(data);
	a += wall_y_down(data);
	if (a == 2 || a == 1)
		return (0);
	return (1);
}

void	direction(t_data *data)
{
	if (data->player.walk_direction == 1)
		cond1(data);
	else if (data->player.walk_direction == -1)
		cond2(data);
	if (data->player.side_direction == 1)
		cond3(data);
	else if (data->player.side_direction == -1)
		cond4(data);
}
