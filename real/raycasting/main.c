/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:43 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/31 15:47:31 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char*)data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	main(int ac, char **av)
{
	t_data data;
	int				rows;
	int				col;

	if (ac == 2)
	{
		data.parsing = malloc(sizeof(t_data_parsing));
		parsing(data.parsing, av[1]);
		rows = calcul_rows(data.parsing->new_map);
		col = calcul_col(data.parsing->new_map);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < col; j++)
				data.grid[i][j] = fill_int(data.parsing->new_map[i][j]);
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
				"cub3d");
		data.img.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH,
				WINDOW_HEIGHT);
		data.img.addr = (int*)mlx_get_data_addr(data.img.img_ptr,
				&data.img.bits_per_pixel, &data.img.lineLength,
				&data.img.endian);
		int x;int y;
		data.img1_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./reload/1.xpm", &y, &x);
		data.op = 0;
		textures_init(&data);
		render_map(&data);
		render_player(&data, data.parsing);
		data.color_ceiling = data.parsing->ceiling_color;
		data.color_floor = data.parsing->floor_color;
		update(&data);
		mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
		mlx_hook(data.win_ptr, 3, 0, key_released, &data);
		mlx_loop_hook(data.mlx_ptr, update, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("%s%s\n",ERROR, WRONG_ARGS);
	return (0);
}
