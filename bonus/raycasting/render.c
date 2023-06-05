/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:29:56 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 22:50:06 by zanejar          ###   ########.fr       */
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

void	mlx_clear_image(t_data *data)
{
	int	color;
	int	x;
	int	y;

	color = BLACK_COLOR;
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y < WINDOW_HEIGHT)
			my_mlx_pixel_put(&data->img, x, y, color);
	}
}

void	ft_mini_map(t_data *data)
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

void	ft_mini_map_player_render(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

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
	}
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
