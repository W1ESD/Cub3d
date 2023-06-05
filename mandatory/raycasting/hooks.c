/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:02 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 02:30:55 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_window(void)
{
	exit(0);
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
	if (keycode == 49)
		data->op = 1;
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
