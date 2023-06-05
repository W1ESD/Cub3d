/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:06 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 03:05:48 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*gnl(int fd)
{
	char	bit;
	char	result[20000];
	int		i;
	int		n;

	i = 0;
	n = read(fd, &bit, 1);
	while (n > 0)
	{
		result[i++] = bit;
		if (bit == '\n')
			break ;
		n = read(fd, &bit, 1);
	}
	if (i == 0 && n <= 0)
		return (0);
	result[i] = '\0';
	return (strdup(result));
}

int	champ(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	print_error(int a)
{
	if (a == 1)
		printf("%s%s\n", ERROR, "Space Error\033[0m");
	if (a == 2)
		printf("%s%s\n", ERROR, "Space Error\033[0m");
	if (a == 3)
		printf("%s%s\n", ERROR, "Space Error\033[0m");
	if (a == 4)
		printf("%s%s\n", ERROR, "Space Error\033[0m");
	exit(1);
}

int	nbr_colone(char **map)
{
	int	i;

	i = 0;
	while (map[++i])
		i++;
	return (i);
}

void	add_text_to_struct(char *ident, char *line, t_data_parsing *data)
{
	if (ident[0] == 'N')
		data->north_txt = strdup(line);
	if (ident[0] == 'S')
		data->south_txt = strdup(line);
	if (ident[0] == 'E')
		data->east_txt = strdup(line);
	if (ident[0] == 'W')
		data->west_txt = strdup(line);
}
