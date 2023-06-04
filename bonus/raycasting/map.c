/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:27:55 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/03 22:58:03 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"     

void render_map(t_data *data)
{
    int x;
	int y; 
	int color;
    int i;
	int j;
	int dx;
	int dy;
	
	i = -1;
    while (++i < data->rows) 
	{
        j = -1;
        while (++j < data->cols) 
		{
            x = j * data->tile_size;
            y = i * data->tile_size;
            color = data->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            dx = -1;
            while (++dx < data->tile_size) 
			{
                dy = -1;
                while (++dy < data->tile_size) 
				{
                    my_mlx_pixel_put(&data->img, (x + dx) * MINI_MAP_SCALE_FACTOR, \
					(y + dy) * MINI_MAP_SCALE_FACTOR, color);
            
                }
            }
        }
    }
}

