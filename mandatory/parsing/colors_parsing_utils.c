/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:57:15 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 03:03:33 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_valid_bit(char *line, int i, t_data_parsing *data, int color)
{
	int	c;

	if (!line)
	{
		printf("%s%s\n", ERROR, "Invalid rgb Color\033[0m");
		exit(1);
	}
	if (count_bits(line))
	{
		printf("%s%s\n", ERROR, "Invalid rgb Color\033[0m");
		exit(1);
	}
	c = ft_atoi(line);
	if (c > 255 || c == -1)
	{
		printf("%s%s\n", ERROR, "Invalid rgb Color\033[0m");
		exit(1);
	}
	if (!color)
		data->floor_color += (c << (16 - i * 8));
	else if (color)
		data->ceiling_color += (c << (16 - i * 8));
}

void	check_flor(char *line, t_data_parsing *data, int color)
{
	int	i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t')
		i++;
	check_format(line + i, data, color);
}

int	count_coma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	init_norm(t_norminette *data)
{
	data->line = gnl(data->fd);
	data->liste = NULL;
	data->i = 6;
}

void	get_done(t_norminette *norm, t_data_parsing *data)
{
	if (norm->line)
		norm->n = valid_line(norm->line);
	while (norm->line && !norm->n)
	{
		data->leaks_task[data->index_leaks++] = norm->line;
		norm->line = gnl(norm->fd);
		if (norm->line)
			norm->n = valid_line(norm->line);
	}
}
