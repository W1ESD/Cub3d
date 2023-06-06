/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:59:02 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 04:03:33 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	wall_y_right(t_data *data)
{
	int	my_x;
	int	my_y;
	int	new_x;
	int	new_y;

	my_x = data->player.x;
	my_y = data->player.y - sin(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
		my_y--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
	{
		if (data->grid[my_y][my_x] == 1)
			return (1);
	}
	return (0);
}

int	wall_x_right(t_data *data)
{
	int	new_x;
	int	new_y;
	int	my_x;
	int	my_y;

	my_x = data->player.x - cos(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	my_y = data->player.y;
	if (my_x < data->player.x && (my_x % (int)data->tile_size == 0))
		my_x--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (new_x < data->cols && new_y < data->rows)
	{
		if (data->grid[new_y][new_x] == 1)
			return (1);
	}
	return (0);
}

int	really_able_right(t_data *data)
{
	int	a;

	a = 0;
	a += wall_x_right(data);
	a += wall_y_right(data);
	if (a == 2 || a == 1)
		return (0);
	return (1);
}

int	wall_y_left(t_data *data)
{
	int	my_x;
	int	my_y;
	int	new_x;
	int	new_y;

	my_x = data->player.x;
	my_y = data->player.y + sin(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
		my_y--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
	{
		if (data->grid[my_y][my_x] == 1)
			return (1);
	}
	return (0);
}

int	wall_x_left(t_data *data)
{
	int	new_x;
	int	new_y;
	int	my_x;
	int	my_y;

	my_x = data->player.x + cos(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	my_y = data->player.y;
	if (my_x < data->player.x && (my_x % (int)data->tile_size == 0))
		my_x--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (new_x < data->cols && new_y < data->rows)
	{
		if (data->grid[new_y][new_x] == 1)
			return (1);
	}
	return (0);
}
