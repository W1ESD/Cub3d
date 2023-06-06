/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:57:06 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/06 02:01:36 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	to_up(double start, double end)
{
	if (end - start > 0)
		return (0);
	return (1);
}

int	able_to_walk_up(t_data *data)
{
	int	my_x;
	int	my_y;

	my_x = cos(data->player.rotation_angle) * data->player.move_speed
		+ data->player.x;
	my_y = sin(data->player.rotation_angle) * data->player.move_speed
		+ data->player.y;
	if (my_y % (int)(data->tile_size) == 0 && to_up(data->player.y,
			sin(data->player.rotation_angle) * data->player.move_speed
			+ data->player.y))
		my_y--;
	if (my_x < data->player.x && (my_x % (int)data->tile_size == 0))
		my_x--;
	my_x = floor(my_x / data->tile_size);
	my_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
		if (data->grid[my_y][my_x] == 1 || data->grid[my_y][my_x] == 6)
			return (0);
	return (1);
}

int	able_to_walk_down(t_data *data)
{
	int	my_x;
	int	my_y;

	my_x = data->player.x - cos(data->player.rotation_angle)
		* data->player.move_speed;
	my_y = data->player.y - sin(data->player.rotation_angle)
		* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
		my_y--;
	if (my_x < data->player.x && (my_x % (int)data->tile_size == 0))
		my_x--;
	my_x = floor(my_x / data->tile_size);
	my_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
		if (data->grid[my_y][my_x] == 1 || data->grid[my_y][my_x] == 6)
			return (0);
	return (1);
}

int	able_to_turn_left(t_data *data)
{
	int	my_x;
	int	my_y;

	my_x = data->player.x + cos(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	my_y = data->player.y + sin(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
		my_y--;
	if (my_x < data->player.x && (my_y % (int)data->tile_size == 0))
		my_x--;
	my_x = floor(my_x / data->tile_size);
	my_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
		if (data->grid[my_y][my_x] == 1 || data->grid[my_y][my_x] == 6)
			return (0);
	return (1);
}

int	able_to_turn_right(t_data *data)
{
	int	my_x;
	int	my_y;

	my_x = data->player.x - cos(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	my_y = data->player.y - sin(data->player.rotation_angle + (PI / 2))
		* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
		my_y--;
	if (my_x < data->player.x && (my_y % (int)data->tile_size == 0))
		my_x--;
	my_x = floor(my_x / data->tile_size);
	my_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
		if (data->grid[my_y][my_x] == 1 || data->grid[my_y][my_x] == 6)
			return (0);
	return (1);
}
