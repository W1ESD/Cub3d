/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:50:41 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 05:24:32 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			printf("%s%s\n", ERROR, "Incorrect First Line\033[0m");
			exit(1);
		}
		i++;
	}
}

void	check_lastline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
		{
			printf("%s%s\n", ERROR, "Walls Error\033[0m");
			exit(1);
		}
		i++;
	}
}

void	enc_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		check_first_last(map[i]);
		i++;
	}
	check_lastline(map[i - 1]);
}

void	closed_map(char **map)
{
	first_line(map[0]);
	enc_map(map);
}

void	check_map_game(t_data_parsing *data)
{
	check_different_digit(data);
	check_player_duplicity(data);
	closed_map(data->map + 6);
}
