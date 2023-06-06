/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:02 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 01:43:17 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	update2(t_data *data)
{
	direction(data);
	ray_caster(data);
	render_3d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	return (0);
}

void	door_step(t_data *data, double x, double y)
{
	int	my_x;
	int	my_y;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
	{
		return ;
	}
	my_x = floor(x / data->tile_size);
	my_y = floor(y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
	{
		if (data->grid[my_y][my_x] == 6)
			data->grid[my_y][my_x] = 9;
		else if (data->grid[my_y][my_x] == 9)
			data->grid[my_y][my_x] = 6;
	}
}

void	open_door(t_data *data)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	x = (cos(data->player.rotation_angle) * 22 + data->player.x);
	y = (sin(data->player.rotation_angle) * 22 + data->player.y);
	door_step(data, x, y);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player.walk_direction = 1;
	else if (keycode == S_KEY)
		data->player.walk_direction = -1;
	else if (keycode == A_KEY)
		data->player.side_direction = -1;
	else if (keycode == D_KEY)
		data->player.side_direction = 1;
	if (keycode == LEFT_KEY)
		data->player.rotation_angle -= data->player.rotation_speed;
	else if (keycode == RIGHT_KEY)
		data->player.rotation_angle += data->player.rotation_speed;
	if (keycode == ESC)
		close_window();
	if (keycode == 15)
		data->op = 1;
	if (keycode == 49)
		open_door(data);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == S_KEY)
		data->player.walk_direction = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		data->player.side_direction = 0;
	return (0);
}
