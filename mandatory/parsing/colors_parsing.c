/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:50:48 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 23:20:47 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_one(t_norminette *norm, char *line)
{
	norm->i = 0;
	norm->line = line;
	while (norm->line[norm->i] == ' ' || norm->line[norm->i] == '\t')
		(norm->i)++;
	norm->coma = count_coma(norm->line + norm->i);
	if (norm->coma != 2)
	{
		printf("%s%s\n", ERROR, "Invalid rgb Color\033[0m");
		exit(1);
	}
	norm->split = NULL;
	norm->split = ft_split2_2(norm->line + norm->i);
	norm->j = 0;
}

void	check_format(char *line, t_data_parsing *data, int color)
{
	t_norminette	norm;

	get_one(&norm, line);
	while (norm.j < 3)
	{
		check_valid_bit(norm.split[norm.j], norm.j, data, color);
		(norm.j)++;
	}
	(norm.i) = 0;
	while (norm.split[norm.i])
	{
		data->leaks_task[data->index_leaks++] = norm.split[norm.i];
		(norm.i)++;
	}
	free(norm.split);
	if (norm.i > 3)
	{
		printf("%s%s\n", ERROR, "Invalid Color\033[0m");
		exit(1);
	}
}

int	is_color(char *str, t_data_parsing *data)
{
	char	**result;
	int		i;
	int		type;

	result = ft_split2(str);
	i = 0;
	type = 0;
	if (!color_valid(result[0]))
		type = 1;
	i = 0;
	while (result[i])
	{
		data->leaks_task[data->index_leaks++] = result[i];
		i++;
	}
	free(result);
	return (type);
}

int	color_type(char *s, t_data_parsing *data)
{
	char	**result;
	int		i;
	int		type;

	result = ft_split2(s);
	i = 0;
	if (ceiling(result[0]))
		type = 1;
	else if (flor(result[0]))
		type = 0;
	i = 0;
	while (result[i])
	{
		data->leaks_task[data->index_leaks++] = result[i];
		i++;
	}
	free(result);
	return (type);
}

void	check_colors(t_data_parsing *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 6)
	{
		if (is_color(data->map[i], data))
		{
			check_flor(data->map[i], data, color_type(data->map[i], data));
			count++;
		}
		i++;
	}
	if (count != 2)
	{
		printf("Invalid Colors\n");
		exit(1);
	}
}
