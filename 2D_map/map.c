/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:27:55 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/13 02:19:30 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
  
void render_map(t_player *player) 
{
    int x, y, color;
    for (int i = 0; i < MAP_NUM_ROWS; i++) {
        for (int j = 0; j < MAP_NUM_COLS; j++) {
            x = j * PIXEL;
            y = i * PIXEL;
            color = player->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            for (int dx = 0; dx < PIXEL; dx++) {
                for (int dy = 0; dy < PIXEL; dy++) {
                    my_mlx_pixel_put(&player->img, x + dx, y + dy, color);
                }
            }
        }
    }
	// mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, player->img.img_ptr, 0, 0);
}
