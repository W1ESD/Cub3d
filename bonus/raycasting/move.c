/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:30:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 03:55:54 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	update(t_data *data)
{
	direction(data);
	ray_caster(data);
	render_3d(data);
	render_map(data);
	player_draw(data);
	ray_caster(data);
	render_animation(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1_ptr, 0, 0);
	return (0);
}
