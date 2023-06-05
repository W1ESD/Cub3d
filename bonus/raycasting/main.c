/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:17:43 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/05 03:04:27 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (char*)data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	func_mouse(int x, int y, void *param)
{
	t_data	*data;
	double	my_speed;

	(void)y;
	data = (t_data *)param;
	my_speed = data->player.rotationSpeed / 4;
	if (x > WINDOW_WIDTH / 2 && x <= WINDOW_WIDTH)
		data->player.rotationAngle += my_speed;
	if (x < WINDOW_WIDTH / 2 && x >= 0)
		data->player.rotationAngle -= my_speed;
	return (1);
}
char	**reload_rd(int fd,t_data_parsing *data_parsing)
{
	char	**gun;
	char	*line_saved;
	char	*readed_bit;
	int		read_index;

	readed_bit = calloc(2, sizeof(char));
	line_saved = strdup("");
	read_index = 1;
	while (read_index != 0)
	{ 
		read_index = read(fd, readed_bit, 1);
		if (read_index == -1)
		{
			data_parsing->leaks_task[data_parsing->index_leaks++] = readed_bit;
			return (NULL);
		}
		if (read_index != 0)
			line_saved = ft_strjoin(line_saved, readed_bit,data_parsing);
	}
	data_parsing->leaks_task[data_parsing->index_leaks++] = readed_bit;
	gun = ft_split(line_saved, '\n',data_parsing);
	data_parsing->leaks_task[data_parsing->index_leaks++] = line_saved;
	return (gun);
}

void	func_picture(t_data* data,t_data_parsing* data_parsing)
{
	int		width;
	int		heigth;
	char	**reload_path;
	int		fd;
	int		i;


	fd = open("gun.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("{File can't be opend}\n");
		exit(0);
	}
	reload_path = reload_rd(fd, data_parsing);
	i = 0;
	while (reload_path[i])
		i++;
	data->iimg = (void **)malloc(sizeof(void *) * i);
	i = 0;
	while (reload_path[i])
	{
		data->iimg[i] = mlx_xpm_file_to_image(data->mlx_ptr, reload_path[i], &width, &heigth);
		i++;
	}
	i = 0;
	while(reload_path[i])
		data_parsing->leaks_task[data_parsing->index_leaks++] = reload_path[i++];
	free(reload_path);
	data->iimg[i] = NULL;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_data data;
		int i;
		int j;
		data.parsing = malloc(sizeof(t_data_parsing));
		
		parsing(data.parsing, av[1]);
		
		data.rows = calcul_rows(data.parsing->new_map);
		data.cols = calcul_col(data.parsing->new_map);
		i = -1;
		data.grid = malloc(sizeof(int*) * data.rows);
		while (++i < data.rows)
		{	
			data.grid[i] = malloc(sizeof(int) * data.cols);
			j = -1;
			while (++j < data.cols)
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
		data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d_bonus");
		data.img.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
 
		data.img.addr = (int*)mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.lineLength, &data.img.endian);
		int x;
		int y;
		data.img1_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./reload/1.xpm", &y, &x);
		data.op = 0;
		
		func_picture(&data,data.parsing);

		data.door_path = "./textures/sideB.xpm";
		textures_init(&data);
		render_map(&data);
		render_player(&data, data.parsing);

		data.color_ceiling = data.parsing->ceiling_color;
		data.color_floor = data.parsing->floor_color;
		
		update(&data);

		mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
		mlx_hook(data.win_ptr, 3, 0, key_released, &data);
		mlx_loop_hook(data.mlx_ptr, update, &data);
		mlx_hook(data.win_ptr, 17, 0, close_window, &data);
		mlx_hook(data.win_ptr, 6, 0, &func_mouse, &data);			//{ 6 for the event 0 for the bitmask options }
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("%s%s\n",ERROR, WRONG_ARGS);
	return (0);
}