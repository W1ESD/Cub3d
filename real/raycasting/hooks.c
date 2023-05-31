/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:02 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/31 15:47:15 by wiessaiy         ###   ########.fr       */
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
			data->player.walkDirection = 1;
	else if (keycode == S_KEY)
			data->player.walkDirection = -1;
	else if (keycode == A_KEY)
			data->player.sideDirection = -1;
	else if (keycode == D_KEY)
			data->player.sideDirection = 1;
	if (keycode == LEFT_KEY)
			data->player.rotationAngle -= data->player.rotationSpeed;
	else if (keycode == RIGHT_KEY)
			data->player.rotationAngle += data->player.rotationSpeed;
	if (keycode == ESC)
			close_window();
	if(keycode == 49)
			data->op = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == S_KEY)
		data->player.walkDirection = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		data->player.sideDirection = 0;
	return (0);
}