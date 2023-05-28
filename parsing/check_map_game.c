/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:50:41 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/28 23:09:27 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_vl(char *s)
{
	int	i;
  
	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'N' && s[i] != 'S'
			&& s[i] != 'E' && s[i] != 'W' && s[i] != ' ')
		{
			printf("%s%s\n", ERROR, "Invalid Map Element\033[0m");
			exit(1);
		}
		i++;
	}
}

void	check_different_digit(t_data_parsing *data)
{
	int	i;

	i = 6;
	while (data->map[i])
	{
		check_vl(data->map[i]);
		i++;
	}
}
void	check_player_duplicity(t_data_parsing *data)
{
	int	i;
	int	j;
	int	count;

	i = 6;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
	{
		printf("%s%s\n", ERROR, "Duplicate Player\033[0m");
		exit(1);
	}
	if (count == 0)
	{
		printf("%s%s\n", ERROR, "No player Founded\033[0m");
		exit(1);
	}
}
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

void	check_first_last(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1' && line[i] != ' ')
	{
		printf("%s%s\n", ERROR, "Walls Error\033[0m");
		exit(1);
	}
	while (line[++i])
		;
	if (line[i - 1] != '1' && line[i - 1] != ' ')
	{
		printf("%s%s\n", ERROR, "Walls Error\033[0m");
		exit(1);
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
