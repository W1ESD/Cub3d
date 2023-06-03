/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:43 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 03:35:26 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char*)data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int main(int ac,char **av)
{	
    if(ac == 2)
    {
		t_data	data;
    	
		data.parsing = malloc(sizeof(t_data_parsing));
		parsing(data.parsing, av[1]);
	
		data.rows = calcul_rows(data.parsing->new_map);
		data.cols =  calcul_col(data.parsing->new_map);
		// printf("cols = %d\n", data.cols);
		// printf("rows = %d\n", data.rows);

		
		data.grid = malloc(sizeof(int*) * (data.rows));
		for (int i = 0; i < data.rows; i++)
		{	
			data.grid[i] = malloc(sizeof(int) * (data.cols));
    		for (int j = 0; j < data.cols; j++)
    		    data.grid[i][j] = fill_int(data.parsing->new_map[i][j]);
		}
		data.pixel_x = floor(WINDOW_HEIGHT / data.cols);
		data.pixel_y = floor(WINDOW_WIDTH / data.rows);
		if(data.pixel_x < data.pixel_y)
		{
			data.tile_size = data.pixel_x;
			data.pixel_y = data.pixel_x;
		}
		else
			data.tile_size = data.pixel_y;
		    
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
		data.img.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
		data.img.addr = (int*)mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, \
		&data.img.lineLength, &data.img.endian);
		
		textures_init(&data);

		render_player(&data, data.parsing);
		
		data.color_ceiling = data.parsing->ceiling_color;
		data.color_floor = data.parsing->floor_color;

		update(&data);
		
		mlx_clear_window(data.mlx_ptr, data.win_ptr);
		mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
		mlx_hook(data.win_ptr, 3, 0, key_released, &data);
		mlx_hook(data.win_ptr, 17, 0, close_window, &data);
		mlx_loop_hook(data.mlx_ptr, update, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("%s%s\n",ERROR, WRONG_ARGS);
		
	return (0);
}