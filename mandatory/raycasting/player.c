/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 02:34:07 by zanejar          ###   ########.fr       */
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

int	able_to_x(t_data *data)
{
	int	my_x;
	int	my_y;
	int	x;
	int	y;

	my_x = data->player.x + cos(data->player.rotation_angle)
		* data->player.move_speed;
	my_y = data->player.y;
	x = floor(my_x / data->tile_size);
	y = floor(my_y / data->tile_size);
	if (x < data->cols && my_y < data->rows)
		if (data->grid[y][x] == 1)
			return (0);
	return (1);
}

int	able_to_y(t_data *data)
{
	int	my_x;
	int	my_y;
	int	x;
	int	y;

	my_x = data->player.x;
	my_y = data->player.y + sin(data->player.rotation_angle)
		* data->player.move_speed;
	x = floor(my_x / data->tile_size);
	y = floor(my_y / data->tile_size);
	if (x < data->cols && y < data->rows)
		if (data->grid[y][x] == 1)
			return (0);
	return (1);
}

int	really_able(t_data *data, int ind)
{
	int	a;
	int	my_x;
	int	my_y;
	int	new_x;
	int	new_y;

	a = 0;
	if (ind == 1)
	{
		my_x = data->player.x + cos(data->player.rotation_angle)
			* data->player.move_speed;
		my_y = data->player.y;
		new_x = floor(my_x / data->tile_size);
		new_y = floor(my_y / data->tile_size);
		if (new_x < data->cols && new_y < data->rows)
			if (data->grid[new_y][new_x] == 1)
				a++;
		my_x = data->player.x;
		my_y = data->player.y + sin(data->player.rotation_angle)
			* data->player.move_speed;
		if (my_y % (int)data->tile_size == 0)
			my_y--;
		new_x = floor(my_x / data->tile_size);
		new_y = floor(my_y / data->tile_size);
		if (my_x < data->cols && my_y < data->rows)
			if (data->grid[my_y][my_x] == 1)
				a++;
		if (a == 2 || a == 1)
			return (0);
	}
	return (1);
}

void	direction(t_data *data)
{
	if (data->player.walk_direction == 1)
	{
		if (able_to_walk_up(data) && really_able(data, 1))
		{
			data->player.x += cos(data->player.rotation_angle)
				* data->player.move_speed;
			data->player.y += sin(data->player.rotation_angle)
				* data->player.move_speed;
		}
	}
	else if (data->player.walk_direction == -1)
	{
		if (able_to_walk_down(data))
		{
			data->player.x -= cos(data->player.rotation_angle)
				* data->player.move_speed;
			data->player.y -= sin(data->player.rotation_angle)
				* data->player.move_speed;
		}
	}
	if (data->player.side_direction == 1)
	{
		if (able_to_turn_left(data))
		{
			data->player.x += cos(data->player.rotation_angle + (PI / 2))
				* data->player.move_speed;
			data->player.y += sin(data->player.rotation_angle + (PI / 2))
				* data->player.move_speed;
		}
	}
	else if (data->player.side_direction == -1)
	{
		if (able_to_turn_right(data))
		{
			data->player.x -= cos(data->player.rotation_angle + (PI / 2))
				* data->player.move_speed;
			data->player.y -= sin(data->player.rotation_angle + (PI / 2))
				* data->player.move_speed;
		}
	}
}
