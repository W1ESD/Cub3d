/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:27:55 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 04:04:22 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_map(t_data *data)
{
	t_vars	vars;

	vars.i = -1;
	while (++vars.i < data->rows)
	{
		vars.j = -1;
		while (++vars.j < data->cols)
		{
			vars.x = vars.j * data->tile_size;
			vars.y = vars.i * data->tile_size;
			if (data->grid[vars.i][vars.j] == 1 || \
			data->grid[vars.i][vars.j] == 6)
				vars.color = 0x0FFFFF;
			else
				vars.color = 0x005FFF;
			vars.dx = -1;
			while (++vars.dx < data->tile_size)
			{
				vars.dy = -1;
				while (++vars.dy < data->tile_size)
				{
					my_mlx_pixel_put(&data->img, (vars.x + vars.dx)
						* MINI_MAP_SCALE_FACTOR, (vars.y + vars.dy)
						* MINI_MAP_SCALE_FACTOR, vars.color);
				}
			}
		}
	}
}
