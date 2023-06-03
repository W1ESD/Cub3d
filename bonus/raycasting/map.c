/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:27:55 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/03 03:20:55 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"     
  
void render_map(t_data *data) 
{
    int x, y, color;
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            x = j * data->tile_size;
            y = i * data->tile_size;
            color = data->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            for (int dx = 0; dx < data->tile_size; dx++) {
                for (int dy = 0; dy < data->tile_size; dy++) {
                    my_mlx_pixel_put(&data->img, (x + dx) * MINI_MAP_SCALE_FACTOR, \
					(y + dy) * MINI_MAP_SCALE_FACTOR, color);
                }
            }
        }
    }
}

