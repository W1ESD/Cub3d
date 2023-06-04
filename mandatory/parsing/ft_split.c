/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:00 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 23:38:19 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}

void	init_ocur(t_norm *norm)
{
	norm->end_cur = 0;
	norm->start_cur = 0;
}

static int	split_words(t_norm *norm, int word, t_data_parsing *data)
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
	norm.result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!norm.result)
		return (NULL);
	if (!split_words(&norm, 0, data))
		return (NULL);
	return (norm.result);
}
