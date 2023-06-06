/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:27:55 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 04:08:52 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_init(t_data *data, t_vars *vars)
{
	vars->x = vars->j * data->tile_size;
	vars->y = vars->i * data->tile_size;
	if (data->grid[vars->i][vars->j] == 1 || \
	data->grid[vars->i][vars->j] == 6)
		vars->color = 0x0FFFFF;
	else
		vars->color = 0x005FFF;
	vars->dx = -1;
}

void	render_map(t_data *data)
{
	t_vars	vars;

	vars.i = -1;
	while (++vars.i < data->rows)
	{
		vars.j = -1;
		while (++vars.j < data->cols)
		{
			render_init(data, &vars);
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

void	dist_calc(t_data *data, int i, int h, int v)
{
	data->ray[i].dh = distance_between_xy(data, data->ray[i].hit_x_h,
			data->ray[i].hit_y_h);
	data->ray[i].dv = distance_between_xy(data, data->ray[i].hit_x_v,
			data->ray[i].hit_y_v);
	if (h == 0)
		return (set_hit1(data, i));
	if (data->ray[i].dh < data->ray[i].dv || (v == 0))
		return (set_hit2(data, i));
	else
		return (set_hit3(data, i));
}

double	distance_between_xy(t_data *data, double hit_x, double hit_y)
{
	double	distance;

	distance = sqrt((hit_x - data->player.x) * (hit_x - data->player.x) + (hit_y
				- data->player.y) * (hit_y - data->player.y));
	return (distance);
}
