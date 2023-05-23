/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:43 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/23 08:41:27 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"  

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac,char **av)
{	

    t_data_parsing  *data_parsing;
    if(ac == 2)
    {
    data_parsing = malloc(sizeof(t_data_parsing));
    parsing(data_parsing,av[1]);
	t_data	data;
	int rows = calcul_rows(data_parsing->new_map);
	int col =  calcul_col(data_parsing->new_map);
	for (int i = 0; i < rows; i++)
    	for (int j = 0; j < col; j++)
    	    data.grid[i][j] = fill_int(data_parsing->new_map[i][j]);
    data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub_2d");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.lineLength, &data.img.endian);
	render_map(&data);
	render_player(&data,data_parsing);
	data.color_ceiling = data_parsing->ceiling_color;
	data.color_floor = data_parsing->floor_color;
	update(&data);
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 0, key_released, &data);
	mlx_loop_hook(data.mlx_ptr, update, &data);
	mlx_loop(data.mlx_ptr);
	}
	return (0);
}
