/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 05:27:02 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/06 02:08:32 by zanejar          ###   ########.fr       */
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
	if (count > 1 || count == 0)
	{
		printf("%s%s\n", ERROR, ":Player Element \033[0m");
		exit(1);
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

int	count_bits(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i > 2)
			return (1);
		i++;
	}
	return (0);
}
