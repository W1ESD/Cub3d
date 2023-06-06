/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 04:05:47 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_draw(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	i;
	int	j;

	x = data->player.x;
	y = data->player.y;
	color = WHITE_COLOR;
	i = -1;
	while (++i < data->player.width)
	{
		j = -1;
		while (++j < data->player.height)
		{
			my_mlx_pixel_put(&data->img, (x + i) * MINI_MAP_SCALE_FACTOR, (y
					+ j) * MINI_MAP_SCALE_FACTOR, color);
		}
		line_drawing(data, x + cos(data->player.rotation_angle) * LINE_LENGTH, y
			+ sin(data->player.rotation_angle) * LINE_LENGTH);
	}
}

void	render_player(t_data *data, t_data_parsing *parsing)
{
	data->player.x = (parsing->player_x) * data->tile_size;
	data->player.y = (parsing->player_y) * data->tile_size;
	data->player.width = 10;
	data->player.height = 10;
	data->player.side_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_angle = get_angle(parsing);
	data->player.move_speed = 2;
	data->player.rotation_speed = (3 * PI) / 100;
	player_draw(data);
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
	if (x < data->cols && y < data->rows)
		if (data->grid[y][x] == 1 || data->grid[y][x] == 6)
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
		if (data->grid[y][x] == 1 || data->grid[y][x] == 6)
			return (0);
	return (1);
}

void	wall_collision_gliss(t_data *data)
{
	if (able_to_x(data))
	{
		data->player.x += cos(data->player.rotation_angle)
			* data->player.move_speed;
	}
	if (able_to_y(data))
	{
		data->player.y += sin(data->player.rotation_angle)
			* data->player.move_speed;
	}
	return ;
}
