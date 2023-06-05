/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:00 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/05 05:12:32 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	words_count(char const *s, char c)
{
	int	index;
	int	word;

	index = 0;
	word = 0;
	while (s[index] != 0)
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == 0))
			word++;
		index++;
	}
	return (word);
}

void	init_ocur(t_norm *norm)
{
	norm->end_cur = 0;
	norm->start_cur = 0;
}

static int	words_splitter(t_norm *norm, int word, t_data_parsing *data)
{
	init_ocur(norm);
	while (norm->s[norm->end_cur])
	{
		if (norm->s[norm->end_cur] == norm->c || norm->s[norm->end_cur] == 0)
			norm->start_cur = norm->end_cur + 1;
		if (norm->s[norm->end_cur] != norm->c && (norm->s[norm->end_cur
					+ 1] == norm->c || norm->s[norm->end_cur + 1] == 0))
		{
			norm->result[word] = malloc(sizeof(char) * (norm->end_cur
						- norm->start_cur + 2));
			if (!norm->result[word])
			{
				while (word++)
					data->leaks_task[data->index_leaks++] = norm->result[word];
				return (0);
			}
			strlcpy(norm->result[word], (norm->s + norm->start_cur),
				norm->end_cur - norm->start_cur + 2);
			word++;
		}
		norm->end_cur++;
	}
	norm->result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c, t_data_parsing *data)
{
	t_norm	norm;

	norm.s = s;
	norm.c = c;
	if (!norm.s)
		return (NULL);
	norm.result = malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!norm.result)
		return (NULL);
	if (!words_splitter(&norm, 0, data))
		return (NULL);
	return (norm.result);
}
