/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:12 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 23:53:00 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_atoi(char *str)
{
	int	result;
	int	s;
	int	f;

	result = 0;
	s = 1;
	f = 1;
	if (*str == '-')
		return (-1);
	while (*str && f)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else
			return (-1);
		str++;
	}
	return (s * result);
}

void	init_join(t_join *join, char *s1, char *s2)
{
	join->s1 = s1;
	join->s2 = s2;
	join->m = 0;
}

void	fun_helper(t_join *join, t_data_parsing *data)
{
	if (!join->m)
		data->leaks_task[data->index_leaks++] = join->s1;
	join->i = -1;
	if (join->s2)
	{
		while (join->s2[++join->i])
		{
			join->str[join->len1] = join->s2[join->i];
			join->len1++;
		}
	}
}

void	fun_help1(t_join *join)
{
	join->str = (char *)malloc(sizeof(char) * (join->len1 + join->len2 + 1));
	join->i = -1;
	if (join->s1)
	{
		while (join->s1[++join->i])
			join->str[join->i] = join->s1[join->i];
	}
	else
		join->m = 1;
}

char	*ft_strjoin(char *s1, char *s2, t_data_parsing *data)
{
	t_join	join;

	init_join(&join, s1, s2);
	if (join.s1 || join.s2)
	{
		if (join.s1)
			join.len1 = strlen(join.s1);
		else
			join.len1 = 0;
		if (join.s2)
			join.len2 = strlen(join.s2);
		else
			join.len2 = 0;
		fun_help1(&join);
		fun_helper(&join, data);
		join.str[join.len1] = '\0';
		return (join.str);
	}
	return (NULL);
}
