/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:22:56 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 05:10:41 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	func(int x, int y, void *param)
{
	t_data	*data;
	double	my_speed;

	(void)y;
	data = (t_data *)param;
	my_speed = data->player.rotation_speed / 4;
	if (x > WINDOW_WIDTH / 2 && x <= WINDOW_WIDTH)
		data->player.rotation_angle += my_speed;
	if (x < WINDOW_WIDTH / 2 && x >= 0)
		data->player.rotation_angle -= my_speed;
	return (1);
}

char	**read_gun(int fd, t_data_parsing *data_parsing)
{
	char	*bit;
	int		readed_bit;
	char	**my_gun;
	char	*save_mod;

	bit = calloc(2, sizeof(char));
	save_mod = strdup("");
	readed_bit = 1;
	while (readed_bit != 0)
	{
		readed_bit = read(fd, bit, 1);
		if (readed_bit == -1)
		{
			data_parsing->leaks_task[data_parsing->index_leaks++] = bit;
			return (NULL);
		}
		if (readed_bit != 0)
			save_mod = ft_strjoin(save_mod, bit, data_parsing);
	}
	data_parsing->leaks_task[data_parsing->index_leaks++] = bit;
	my_gun = ft_split(save_mod, '\n', data_parsing);
	data_parsing->leaks_task[data_parsing->index_leaks++] = save_mod;
	return (my_gun);
}

void	func_picture(t_data *data, t_data_parsing *data_parsing)
{
	int		width;
	int		heigth;
	char	**images_file;
	int		fd;
	int		i;

	fd = open("gun.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open file error\n");
		exit(0);
	}
	images_file = read_gun(fd, data_parsing);
	i = 0;
	while (images_file[i])
		i++;
	data->iimg = (void **)malloc(sizeof(void *) * i);
	i = 0;
	while (images_file[i])
	{
		data->iimg[i] = mlx_xpm_file_to_image(data->mlx_ptr, images_file[i], &width, &heigth);
		i++;
	}
	i = 0;
	while (images_file[i])
	{
		data_parsing->leaks_task[data_parsing->index_leaks++] = images_file[i++];
	}
	free(images_file);
	data->iimg[i] = NULL;
}
