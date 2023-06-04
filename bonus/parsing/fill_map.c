/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:50:55 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 23:21:10 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_done5(t_norminette *norm, t_data_parsing *data)
{
	norm->splited_map = NULL;
	if (norm->liste)
		norm->splited_map = ft_split(norm->liste, '\n', data);
	data->leaks_task[data->index_leaks++] = norm->liste;
}

void	follow_to_map(char **map, int fd, t_data_parsing *data)
{
	t_norminette	norm;
	int				j;

	norm.fd = fd;
	init_norm(&norm);
	map[6] = NULL;
	get_done(&norm, data);
	get_done2(&norm, data);
	get_done3(&norm, data);
	get_done4(&norm, data);
	get_done5(&norm, data);
	j = 0;
	if (norm.splited_map)
	{
		while (norm.splited_map[j])
		{
			map[norm.i] = norm.splited_map[j];
			norm.i++;
			j++;
		}
	}
	map[norm.i] = NULL;
	check_err(map);
	free(norm.splited_map);
}

void	init_dt(t_norm *norm, int fd)
{
	norm->fd = fd;
	norm->count = 0;
	norm->i = 0;
	norm->line = gnl(norm->fd);
}

void	nrm(t_norm *norm, t_data_parsing *data)
{
	while (norm->line)
	{
		if (valid_line(norm->line))
		{
			norm->liste = ft_strjoin(norm->liste, norm->line, data);
			norm->count++;
		}
		data->leaks_task[data->index_leaks++] = norm->line;
		if (norm->count >= 6)
			break ;
		norm->line = gnl(norm->fd);
	}
}

void	fill_map(char **map, int fd, t_data_parsing *data)
{
	t_norm	norm;

	init_dt(&norm, fd);
	nrm(&norm, data);
	norm.split = ft_split(norm.liste, '\n', data);
	data->leaks_task[data->index_leaks++] = norm.liste;
	if (norm.count < 6)
	{
		data->error_msg = "Incomplete Map\033[0m\n";
		printf("%s%s", ERROR, data->error_msg);
		exit(1);
	}
	while (norm.split[norm.i])
	{
		map[norm.i] = norm.split[norm.i];
		(norm.i)++;
	}
	free(norm.split);
	follow_to_map(map, fd, data);
	data->map = map;
}
