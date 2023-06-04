/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_new_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:52:16 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 02:48:08 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_mochkil(char **map, int n, int m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '+')
			{
				if (i - 1 >= 0 && i - 1 <= m && champ(map[i - 1][j]))
					print_error(1);
				if (i + 1 >= 0 && i + 1 < m && champ(map[i + 1][j]))
					print_error(2);
				if (j + 1 >= 0 && j + 1 <= n && champ(map[i][j + 1]))
					print_error(3);
				if (j - 1 >= 0 && j - 1 <= n && champ(map[i][j - 1]))
					print_error(4);
			}
			j++;
		}
		i++;
	}
}

void	fill_line(char *line, char *new_line, int max_line)
{
	int	i;
	int	a;

	i = 0;
	a = strlen(line);
	while (i < max_line)
	{
		if (line[i] != ' ' && line[i])
			new_line[i] = line[i];
		else
			new_line[i] = '+';
		if (i > a)
			new_line[i] = '+';
		i++;
	}
	new_line[i] = '\0';
}

void	fill_new_map(char **map, char **new_map, int max_line,
		t_data_parsing *data)
{
	int	i;

	i = 0;
	(void)data;
	while (map[i])
	{
		fill_line(map[i], new_map[i], max_line);
		i++;
	}
	if (new_map[i])
		data->leaks_task[data->index_leaks++] = new_map[i];
	new_map[i] = map[i];
}

int	max_size(char **map)
{
	int	i;
	int	nbr;
	int	max;

	i = 0;
	nbr = 0;
	max = 0;
	while (map[i])
	{
		nbr = strlen(map[i]);
		if (nbr > max)
			max = nbr;
		i++;
	}
	return (max);
}

void	check_lfaraghat(char **map, t_data_parsing *data)
{
	int		i;
	int		n;
	char	**new_map;
	int		collum;

	i = 0;
	n = max_size(map);
	collum = nbr_colone(map) - 1;
	new_map = malloc(sizeof(char *) * (collum + 1));
	data->new_map = new_map;
	while (i < collum + 1)
	{
		new_map[i] = malloc(n + 1);
		data->new_map[i] = new_map[i];
		i++;
	}
	fill_new_map(map, new_map, n, data);
	check_mochkil(new_map, n, collum);
}
