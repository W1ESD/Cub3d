/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:18:28 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 03:06:21 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_spaces_with_walls(t_data_parsing *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->new_map[i])
	{
		j = 0;
		while (data->new_map[i][j])
		{
			if (data->new_map[i][j] == '+')
				data->new_map[i][j] = '1';
			j++;
		}
		i++;
	}
	return ;
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

void	init_sp2(t_split *sp2)
{
	sp2->i = 0;
	sp2->j = 0;
	sp2->k = 0;
	sp2->wc = 0;
}

void	check_err(char **map)
{
	if (!map[6])
	{
		printf("%s%s\n", ERROR, "Incomplete Map \033[0m");
		exit(0);
	}
}

void	get_done4(t_norminette *norm, t_data_parsing *data)
{
	if (norm->line && norm->n)
	{
		data->leaks_task[data->index_leaks++] = norm->line;
		printf("%s%s\n", ERROR, "Map Line Error \033[0m");
		exit(0);
	}
}
