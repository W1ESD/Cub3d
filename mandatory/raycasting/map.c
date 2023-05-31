/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:27:55 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/31 11:46:15 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"     

void render_map(t_data *data) 
{
    int x, y, color;
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            x = j * PIXEL;
            y = i * PIXEL;
            color = data->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            for (int dx = 0; dx < PIXEL; dx++) {
                for (int dy = 0; dy < PIXEL; dy++) {
                    my_mlx_pixel_put(&data->img, (x + dx) * MINI_MAP_SCALE_FACTOR, \
					(y + dy) * MINI_MAP_SCALE_FACTOR, color);
                }
            }
        }
    }
	
}

