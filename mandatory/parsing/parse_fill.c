/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:38 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 03:03:53 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_duplicity(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = i + 1;
		while (j < 6)
		{
			if (map[i][0] == map[j][0])
			{
				printf("%s%s\n", ERROR, "Duplicate Identifier Founded\033[0m");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	parse_fill(t_data_parsing *data)
{
	check_text(data);
	check_duplicity(data->map);
	check_colors(data);
	check_map_game(data);
	check_lfaraghat(data->map + 6, data);
}

int	color_valid(char *s)
{
	if (!strcmp(s, "C"))
		return (0);
	if (!strcmp(s, "F"))
		return (0);
	return (1);
}

int	flor(char *s)
{
	if (strcmp(s, "F") == 0)
		return (1);
	return (0);
}

int	ceiling(char *s)
{
	if (strcmp(s, "C") == 0)
		return (1);
	return (0);
}
