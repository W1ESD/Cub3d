/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:47:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 02:18:38 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	adjust_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
	{
		angle = (2 * PI) + angle;
	}
	return (angle);
}

int	found_wall(t_data *data, int x, int y)
{
	int	my_x;
	int	my_y;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (1);
	my_x = floor(x / data->tile_size);
	my_y = floor(y / data->tile_size);
	if (my_x < data->cols && my_y < data->rows)
		if (data->grid[my_y][my_x] == 1)
			return (1);
	return (0);
}

int	is_ray_facing_down(double my_angle)
{
	if (my_angle > 0 && my_angle < PI)
		return (1);
	return (0);
}

int	is_ray_facing_right(double my_angle)
{
	if (my_angle < PI / 2 || my_angle > 3 * PI / 2)
		return (1);
	return (0);
}
