/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:28:02 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/25 08:37:25 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_window(void)
{
	exit(0);
}
int update2(t_data *data) 
{
	// void	*img1_ptr;
	// int width = WINDOW_WIDTH;
	// int height = WINDOW_HEIGHT;
	// img1_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "frame1.xpm", &width, &height);
	direction(data);
	render_map(data);
	player_draw(data);
	ray_caster(data);
	render_3d(data);
	// ft_mini_map(data);
	// ft_mini_map_player_render(data);
	// ray_caster(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img1_ptr, 0, 0);
	//mlx_clear_image(data);
	return (0);
}
void	func_picture(t_data* data)
{
	if (data->op >= 0 && data->op <= 4)
			data->op = (data->op % 4) + 1;
	else
		printf("hello");
	// int width = WINDOW_WIDTH;
	// int height = WINDOW_HEIGHT;
	// void	*frame2;
	// void	*frame3;
	// void	*frame4;
	// void	*frame5;
	// void	*frame6;
	// void	*frame7;
	// void	*frame8;
	// void	*frame9;
	// void	*frame10;
	// void	*frame11;
	// void	*frame12;
	// void	*frame13;
	// void	*frame14;
	// void	*frame15;
	// void	*frame16;
	// void	*frame17;
	

	// frame2 = mlx_xpm_file_to_image(data->mlx_ptr, "frame2.xpm", &width, &height);
	// frame3 = mlx_xpm_file_to_image(data->mlx_ptr, "frame3.xpm", &width, &height);
	// frame4 = mlx_xpm_file_to_image(data->mlx_ptr, "frame4.xpm", &width, &height);
	// frame5 = mlx_xpm_file_to_image(data->mlx_ptr, "frame5.xpm", &width, &height);
	// frame6 = mlx_xpm_file_to_image(data->mlx_ptr, "frame6.xpm", &width, &height);
	// frame7 = mlx_xpm_file_to_image(data->mlx_ptr, "frame7.xpm", &width, &height);
	// frame8 = mlx_xpm_file_to_image(data->mlx_ptr, "frame8.xpm", &width, &height);
	// frame9 = mlx_xpm_file_to_image(data->mlx_ptr, "frame9.xpm", &width, &height);
	// frame10 = mlx_xpm_file_to_image(data->mlx_ptr, "frame10.xpm", &width, &height);
	// frame11 = mlx_xpm_file_to_image(data->mlx_ptr, "frame11.xpm", &width, &height);
	// frame12 = mlx_xpm_file_to_image(data->mlx_ptr, "frame12.xpm", &width, &height);
	// frame13 = mlx_xpm_file_to_image(data->mlx_ptr, "frame13.xpm", &width, &height);
	// frame14 = mlx_xpm_file_to_image(data->mlx_ptr, "frame14.xpm", &width, &height);
	// frame15 = mlx_xpm_file_to_image(data->mlx_ptr, "frame15.xpm", &width, &height);
	// frame16 = mlx_xpm_file_to_image(data->mlx_ptr, "frame16.xpm", &width, &height);
	// frame17 = mlx_xpm_file_to_image(data->mlx_ptr, "frame17.xpm", &width, &height);

	// update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame2, 0, 0);update2(data);
	//  sleep(1);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame3, 0, 0);update2(data);
	//  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame4, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame5, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame6, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame7, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame8, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame9, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame10, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame11, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame12, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame13, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame14, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame15, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame16, 0, 0);update2(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame17, 0, 0);update2(data);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player.walkDirection = 1;
	else if (keycode == S_KEY)
		data->player.walkDirection = -1;
	else if (keycode == A_KEY)
		data->player.sideDirection = -1;
	else if (keycode == D_KEY)
		data->player.sideDirection = 1;
	if (keycode == LEFT_KEY)
		data->player.rotationAngle -= data->player.rotationSpeed;
	else if (keycode == RIGHT_KEY)
		data->player.rotationAngle += data->player.rotationSpeed;
	if (keycode == ESC)
		close_window();
	if(keycode == 49)
		func_picture(data);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == S_KEY)
		data->player.walkDirection = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		data->player.sideDirection = 0;
	return (0);
}