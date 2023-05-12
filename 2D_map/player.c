/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:04 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/12 06:11:20 by wiessaiy         ###   ########.fr       */
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
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x + i, y + j, color);
		}
	}
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x - i, y - j, color);
		}
	}
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x - i, y + j, color);
		}
	}
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x + i, y - j, color);
		}
	}
	line_drawing(player,x + cos(player->rotationAngle) * line_length \
	,y +  sin(player->rotationAngle) * line_length);
	ray_draw(player);
}


void render_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->width = 5;
	player->height = 5;
	player->sideDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = PI / 2;
	player->moveSpeed = 7;
	player->rotationSpeed =  PI / 4 ;
	float 	x, y;
	int 	color;
	x = player->x;
	y = player->y;
	color = 0xFFFFFF;
	player_draw(player);
}

void direction(t_player *player)
{
	if (player->walkDirection == 1)
	{
		player->x += cos(player->rotationAngle) * player->moveSpeed;
		player->y += sin(player->rotationAngle) * player->moveSpeed;
	}
	else if (player->walkDirection == -1)
	{
		player->x -= cos(player->rotationAngle) * player->moveSpeed;
		player->y -= sin(player->rotationAngle) * player->moveSpeed;
	}
	if (player->sideDirection == 1)
		player->x += player->moveSpeed;
	else if (player->sideDirection == -1)
		player->x -= player->moveSpeed;
}

int update(t_player *player) 
{ 
	mlx_hook(player->win_ptr, 2, 0, key_pressed, player);
	direction(player);
	mlx_hook(player->win_ptr, 3, 0, key_released, player);
	render_map(player);
	player_draw(player);
	return (0);
}
