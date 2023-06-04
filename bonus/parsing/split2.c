/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:52:05 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 02:33:23 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init2(t_split *sp2, char *str)
{
	while (str[sp2->i])
	{
		while (str[sp2->i] && (str[sp2->i] == ' ' || str[sp2->i] == '\t'
				|| str[sp2->i] == '\n' || str[sp2->i] == ','))
			sp2->i++;
		if (str[sp2->i])
			sp2->wc++;
		while (str[sp2->i] && (str[sp2->i] != ' ' && str[sp2->i] != '\t'
				&& str[sp2->i] != '\n' && str[sp2->i] != ','))
			(sp2->i)++;
	}
	sp2->out = (char **)malloc(sizeof(char *) * (sp2->wc + 1));
	sp2->i = 0;
}

char	**ft_split2_2(char *str)
{
	t_split	sp2;

	init_sp2(&sp2);
	init2(&sp2, str);
	while (str[sp2.i])
	{
		while (str[sp2.i] && (str[sp2.i] == ' ' || str[sp2.i] == '\t'
				|| str[sp2.i] == '\n' || str[sp2.i] == ','))
			sp2.i++;
		sp2.j = sp2.i;
		while (str[sp2.i] && (str[sp2.i] != ' ' && str[sp2.i] != '\t'
				&& str[sp2.i] != '\n' && str[sp2.i] != ','))
			sp2.i++;
		if (sp2.i > sp2.j)
		{
			sp2.out[sp2.k] = (char *)malloc(sizeof(char) * ((sp2.i - sp2.j)
						+ 1));
			ft_strncpy(sp2.out[sp2.k++], &str[sp2.j], sp2.i - sp2.j);
		}
	}
	sp2.out[sp2.k] = NULL;
	return (sp2.out);
}

void	init_all(t_split *sp)
{
	sp->i = 0;
	sp->j = 0;
	sp->k = 0;
	sp->wc = 0;
}

void	split2_helper(t_split *sp, char *str)
{
	while (str[sp->i])
	{
		while (str[sp->i] && (str[sp->i] == ' ' || str[sp->i] == '\t'
				|| str[sp->i] == '\n'))
			sp->i++;
		if (str[sp->i])
			sp->wc++;
		while (str[sp->i] && (str[sp->i] != ' ' && str[sp->i] != '\t'
				&& str[sp->i] != '\n'))
			sp->i++;
	}
}

char	**ft_split2(char *str)
{
	t_split	sp;

	init_all(&sp);
	split2_helper(&sp, str);
	sp.out = (char **)malloc(sizeof(char *) * (sp.wc + 1));
	sp.i = 0;
	while (str[sp.i])
	{
		while (str[sp.i] && (str[sp.i] == ' ' || str[sp.i] == '\t'
				|| str[sp.i] == '\n'))
			sp.i++;
		sp.j = sp.i;
		while (str[sp.i] && (str[sp.i] != ' ' && str[sp.i] != '\t'
				&& str[sp.i] != '\n'))
			sp.i++;
		if (sp.i > sp.j)
		{
			sp.out[sp.k] = (char *)malloc(sizeof(char) * ((sp.i - sp.j) + 1));
			ft_strncpy(sp.out[sp.k++], &str[sp.j], sp.i - sp.j);
		}
	}
	sp.out[sp.k] = NULL;
	return (sp.out);
}
