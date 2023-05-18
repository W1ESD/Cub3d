/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/18 05:35:30 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void player_draw(t_player *player)
{
	int x, y, color;
	x = player->x;
	y = player->y;
	color = 0xFFFFFF;
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			my_mlx_pixel_put(&player->img, x + i, y + j, color);
		}
	}
	ray_caster(player);
	printf("%f\n", player->hit_distance);
}


void render_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->width = 1;
	player->height = 1;
	player->sideDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = PI / 2;
	player->moveSpeed = 2;
	player->rotationSpeed = (3 * PI) / 100;
	player_draw(player);
}

void direction(t_player *player)
{		
	if (player->walkDirection == 1 && able_to_walk_up(player))
	{
		player->x += cos(player->rotationAngle) * player->moveSpeed;
		player->y += sin(player->rotationAngle) * player->moveSpeed;
	}
	else if (player->walkDirection == -1 && able_to_walk_down(player))
	{
		player->x -= cos(player->rotationAngle) * player->moveSpeed;
		player->y -= sin(player->rotationAngle) * player->moveSpeed;
	}
	if (player->sideDirection == 1 && able_to_turn_left(player)) 
	{
   		player->x += cos(player->rotationAngle + (PI / 2)) * player->moveSpeed;
   		player->y += sin(player->rotationAngle + (PI / 2)) * player->moveSpeed;
	}
	else if (player->sideDirection == -1 && able_to_turn_right(player)) 
	{
	    player->x -= cos(player->rotationAngle + (PI / 2)) * player->moveSpeed;
	    player->y -= sin(player->rotationAngle + (PI / 2)) * player->moveSpeed;
	}
}

int update(t_player *player) 
{
	direction(player);
	render_map(player);
	player_draw(player);
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, player->img.img_ptr, 0, 0);
	return (0);
}
