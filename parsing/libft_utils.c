/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:12 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/28 23:09:07 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


 

char	*ft_strjoin(char  *s1, char  *s2,t_data_parsing *data)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;
	int		m=0;
 
	if (s1 || s2)
	{
        if(s1)
		    len1 = strlen(s1);
        else
            len1 = 0;
        if(s2)
		    len2 = strlen(s2);
        else
            len2 = 0;
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		if(s1){
		while (s1[++i])
			str[i] = s1[i];
		}
		else
		{
			m = 1;
		}
		if(!m)
		{
			data->leaks_task[data->index_leaks++] = s1;
			// (s1);
		}
		i = -1;
        if(s2)
        {
		    while (s2[++i])
		    {
			    str[len1] = s2[i];
			    len1++;
		    }
        }
		
		str[len1] = '\0';
		return (str);
	}
    
	return (NULL);
}