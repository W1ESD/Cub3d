/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:52:11 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 02:41:29 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_path(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	else
		return (1);
}

int	check_identifier(char *str)
{
	return (strcmp(str, "NO") && strcmp(str, "EA") && strcmp(str, "WE")
		&& strcmp(str, "SO") && strcmp(str, "C") && strcmp(str, "F"));
}

void	print_err(int index)
{
	if (index == 1)
		printf("%s%s\n", ERROR, "Invalid Identifier for Texter\033[0m");
	if (index == 2)
		printf("%s%s\n", ERROR, "Invalid texter\033[0m");
	if (index == 3)
		printf("%s%s\n", ERROR, "Invalid texter path\033[0m");
	if (index == 4)
		printf("%s%s\n", ERROR, "Invalid Line for texters\033[0m");
	exit(1);
}

void	check_validity(char *line, t_data_parsing *data)
{
	char	**split;
	int		i;

	split = ft_split2(line);
	if (check_identifier(split[0]))
		print_err(1);
	if (strcmp(split[0], "C") && strcmp(split[0], "F"))
	{
		if (split[1] == NULL)
			print_err(2);
		if (check_path(split[1]) == 0)
			print_err(3);
		if (split[2] != NULL)
			print_err(4);
		add_text_to_struct(split[0], split[1], data);
	}
	i = 0;
	while (split[i])
	{
		data->leaks_task[data->index_leaks++] = split[i];
		i++;
	}
	free(split);
}

void	check_text(t_data_parsing *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		check_validity(data->map[i], data);
		i++;
	}
}
