/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:29:56 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 01:54:01 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	direction(t_data *data)
{
	if (data->player.walk_direction == 1)
		cond1(data);
	else if (data->player.walk_direction == -1)
		cond2(data);
	if (data->player.side_direction == 1)
		cond3(data);
	else if (data->player.side_direction == -1)
		cond4(data);
}

void	render_animation(t_data *data)
{
	int		i;

	if (data->op)
	{
		i = 0;
		while (i < 10)
		{
			update2(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->iimg[i],
				0, 0);
			mlx_do_sync(data->mlx_ptr);
			i++;
		}
		data->op = 0;
	}
	return ;
}
