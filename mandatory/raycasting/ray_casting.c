/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:26 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 03:35:31 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void	ray_caster(t_data *data)
{
	data->wall.projection = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	int i = 0;

	data->ray[i].ray_angle = data->player.rotationAngle - (FOV / 2);
	while(i < NBR_RAYS)
	{
		cast_ray(data, i);
		if (i + 1 < NBR_RAYS)
			data->ray[i + 1].ray_angle = data->player.rotationAngle + (atan((i - (NBR_RAYS / 2)) / data->wall.projection));
		i++;
	}
}       