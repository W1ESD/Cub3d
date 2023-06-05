/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:30:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 22:04:20 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int wall_y(t_data* data)
{
	int my_x;
	int my_y;
	int new_x;
	int new_y;
	
	my_x = data->player.x;
	my_y = data->player.y + sin(data->player.rotation_angle)
			* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
			my_y--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
	{
		if (data->grid[my_y][my_x] == 1)
			return(1);
	}
	return 0;
}

int	wall_x(t_data* data)
{
	int	new_x;
	int	new_y;
	int my_x;
	int my_y;
	
	my_x = data->player.x + cos(data->player.rotation_angle)
			* data->player.move_speed;
		my_y = data->player.y;
	if (my_x < data->player.x && (my_x % (int)data->tile_size == 0))
			my_x--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (new_x < data->cols && new_y < data->rows)
	{
		if (data->grid[new_y][new_x] == 1)
				return(1);
	}
	return 0;
}
int wall_y_down(t_data* data)
{
	int my_x;
	int my_y;
	int new_x;
	int new_y;
	
	my_x = data->player.x;
	my_y = data->player.y - sin(data->player.rotation_angle)
 			* data->player.move_speed;
	if (my_y < data->player.y && (my_y % (int)data->tile_size == 0))
			my_y--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
	{
		if (data->grid[my_y][my_x] == 1)
			return(1);
	}
	return 0;
}

int	wall_x_down(t_data* data)
{
	int	new_x;
	int	new_y;
	int my_x;
	int my_y;
	
 	my_x = data->player.x - cos(data->player.rotation_angle)
 			* data->player.move_speed;
 	my_y = data->player.y;
	if (my_x < data->player.x && (my_x % (int)data->tile_size == 0))
			my_x--;
	new_x = floor(my_x / data->tile_size);
	new_y = floor(my_y / data->tile_size);
	if (new_x < data->cols && new_y < data->rows)
	{
		if (data->grid[new_y][new_x] == 1)
				return(1);
	}
	return 0;
}
int	really_able_up(t_data* data)
{
	int	a;
	int	my_x;
	int	my_y;
	
		a = 0;
		a += wall_x(data);
		a += wall_y(data);
		if (a == 2 || a == 1)
			return (0);
		my_x = data->player.x;
		my_y = data->player.y;
		if((my_x % (int)data->tile_size == 0) && (my_y % (int)data->tile_size == 0))
			return 0;
		return 1;
}

int	really_able_down(t_data* data)
{
	int	a;
	int	my_x;
	int	my_y;
	
		a = 0;
		a += wall_x_down(data);
		a += wall_y_down(data);
		if (a == 2 || a == 1)
			return (0);
		my_x = data->player.x;
		my_y = data->player.y;
		if((my_x % (int)data->tile_size == 0) && (my_y % (int)data->tile_size == 0))
			return 0;
		return 1;
}

int	update(t_data *data)
{
	direction(data);
	render_map(data);
	player_draw(data);
	ray_caster(data);
	render_3d(data);
	ft_mini_map(data);
	ft_mini_map_player_render(data);
	ray_caster(data);
	render_animation(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1_ptr, 0, 0);
	mlx_clear_image(data);
	return (0);
}
