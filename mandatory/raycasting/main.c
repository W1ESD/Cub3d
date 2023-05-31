/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:43 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/31 14:41:49 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"  

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char*) data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void textures_init(t_data *data)
{
	data->parsing->north_txt = mlx_xpm_file_to_image(data->mlx_ptr,\
	data->parsing->north_txt, &data->parsing->i, &data->parsing->j);
	data->parsing->south_txt = mlx_xpm_file_to_image(data->mlx_ptr,\
	data->parsing->south_txt, &data->parsing->i, &data->parsing->j);
	data->parsing->west_txt = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->parsing->west_txt, &data->parsing->i, &data->parsing->j);
	data->parsing->east_txt = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->parsing->east_txt, &data->parsing->i, &data->parsing->j);

	data->texture[0].addr = (int*)mlx_get_data_addr(data->parsing->north_txt,\
	&data->texture[0].bits_per_pixel, &data->texture[0].lineLength, &data->texture[0].endian);
	data->texture[1].addr = (int*)mlx_get_data_addr(data->parsing->south_txt,\
	&data->texture[1].bits_per_pixel, &data->texture[1].lineLength, &data->texture[1].endian);
	data->texture[2].addr = (int*)mlx_get_data_addr(data->parsing->west_txt, \
	&data->texture[2].bits_per_pixel, &data->texture[2].lineLength, &data->texture[2].endian);
	data->texture[3].addr = (int*)mlx_get_data_addr(data->parsing->east_txt, \
	&data->texture[3].bits_per_pixel, &data->texture[3].lineLength, &data->texture[3].endian);
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
		
		// data.grid = malloc(sizeof(int*) * data.rows);
		for (int i = 0; i < data.rows; i++)
		{	
			// data.grid[i] = malloc(sizeof(int) * data.cols);
    		for (int j = 0; j < data.cols; j++)
    		    data.grid[i][j] = fill_int(data.parsing->new_map[i][j]);
		}
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub_2d");
		data.img.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
		data.img.addr = (int*)mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, \
		&data.img.lineLength, &data.img.endian);
		
		textures_init(&data);
		
		// render_map(&data);
		render_player(&data, data.parsing);
		
		data.color_ceiling = data.parsing->ceiling_color;
		data.color_floor = data.parsing->floor_color;

		update(&data);
		
		mlx_clear_window(data.mlx_ptr, data.win_ptr);
		mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
		mlx_hook(data.win_ptr, 3, 0, key_released, &data);
		mlx_loop_hook(data.mlx_ptr, update, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("%s%s\n",ERROR, WRONG_ARGS);
		
	return (0);
}