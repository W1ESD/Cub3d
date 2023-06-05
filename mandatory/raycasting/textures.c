/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:37:52 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/05 23:09:59 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	textures_data(t_data *data)
{
	data->texture[0].addr = (int *)mlx_get_data_addr(data->parsing->north_txt, \
	&data->texture[0].bits_per_pixel, &data->texture[0].line_length, \
	&data->texture[0].endian);
	data->texture[1].addr = (int *)mlx_get_data_addr(data->parsing->south_txt, \
	&data->texture[1].bits_per_pixel, &data->texture[1].line_length, \
	&data->texture[1].endian);
	data->texture[2].addr = (int *)mlx_get_data_addr(data->parsing->west_txt, \
	&data->texture[2].bits_per_pixel, &data->texture[2].line_length, \
	&data->texture[2].endian);
	data->texture[3].addr = (int *)mlx_get_data_addr(data->parsing->east_txt, \
	&data->texture[3].bits_per_pixel, &data->texture[3].line_length, \
	&data->texture[3].endian);
}

void	textures_init(t_data *data)
{
	data->parsing->leaks_task[data->parsing->index_leaks++] = \
	data->parsing->north_txt;
	data->parsing->leaks_task[data->parsing->index_leaks++] = \
	data->parsing->south_txt;
	data->parsing->leaks_task[data->parsing->index_leaks++] = \
	data->parsing->west_txt;
	data->parsing->leaks_task[data->parsing->index_leaks++] = \
	data->parsing->east_txt;
	data->parsing->north_txt = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->parsing->north_txt, &data->parsing->i, &data->parsing->j);
	data->parsing->south_txt = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->parsing->south_txt, &data->parsing->i, &data->parsing->j);
	data->parsing->west_txt = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->parsing->west_txt, &data->parsing->i, &data->parsing->j);
	data->parsing->east_txt = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->parsing->east_txt, &data->parsing->i, &data->parsing->j);
	textures_data(data);
}
