/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:22:56 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 03:29:21 by zanejar          ###   ########.fr       */
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

char	**ft_add_map(int fd, t_data_parsing *data_parsing)
{
	char	**map;
	char	*saver;
	char	*buff;
	int		rb;

	buff = calloc(2, sizeof(char));
	if (!buff)
		return (NULL);
	saver = strdup("");
	rb = 1;
	while (rb != 0)
	{
		rb = read(fd, buff, 1);
		if (rb == -1)
		{
			data_parsing->leaks_task[data_parsing->index_leaks++] = buff;
			return (NULL);
		}
		if (rb != 0)
			saver = ft_strjoin(saver, buff, data_parsing);
	}
	data_parsing->leaks_task[data_parsing->index_leaks++] = buff;
	map = ft_split(saver, '\n', data_parsing);
	data_parsing->leaks_task[data_parsing->index_leaks++] = saver;
	return (map);
}

void	func_picture(t_data *data, t_data_parsing *data_parsing)
{
	int		w;
	int		h;
	char	**path;
	int		fd;
	int		i;

	fd = open("gun.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open error\n");
		exit(0);
	}
	path = ft_add_map(fd, data_parsing);
	i = 0;
	while (path[i])
		i++;
	data->iimg = (void **)malloc(sizeof(void *) * i);
	i = 0;
	while (path[i])
	{
		data->iimg[i] = mlx_xpm_file_to_image(data->mlx_ptr, path[i], &w, &h);
		i++;
	}
	i = 0;
	while (path[i])
	{
		data_parsing->leaks_task[data_parsing->index_leaks++] = path[i++];
	}
	free(path);
	data->iimg[i] = NULL;
}
