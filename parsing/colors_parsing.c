/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:50:48 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/23 09:13:23 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int     count_bits(char     *line)
{
    int     i=0;
    while(line[i])
    {
        if(i > 2)
            return (1);
        i++;
    }
    return(0);
}

int		ft_atoi(char *str)
{
	int	sum;
	int	sign;
	int	found;

	sum = 0;
	sign = 1;
	found = 1;
	if (*str == '-') 
		return(-1);
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else 
			return(-1);
		str++;
	}
	return (sign * sum);
}

void    check_valid_bit(char    *line,int i,t_data_parsing *data,int color)
{
    if(!line)
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    if(count_bits(line))
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    int     c = ft_atoi(line);
    if( c > 255 || c == -1)
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    if(!color)
        data->floor_color   += (c << (16 - i * 8));
    else if (color)
        data->ceiling_color += (c << (16 - i * 8));
}

int     count_coma(char *line)
{
    int     i = 0;
    int     count=0;
    while (line[i])
    {   
        if(line[i] == ',')
            count++;
    i++;
    }
    return(count);
}
void    check_format(char   *line,t_data_parsing *data,int color)
{
    int     i = 0;

    while (line[i] == ' ' || line[i] == '\t')
            i++;
    int coma = count_coma(line + i);
    if(coma != 2)
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    char    **split = NULL;
    split = ft_split2_2(line + i);
    int     j=0;
    //printf("%d\n",color);
    while(j < 3)
    {
        check_valid_bit(split[j],j,data,color);
        j++;
    }
    i=0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
    if(i > 3)
    {
        printf("%s%s\n",ERROR,"Invalid Color\033[0m");
        exit(1);
    }
}

void    check_flor(char     *line,t_data_parsing* data,int color)
{
    int i = 0;
    while(line[i] != ' ' && line[i] != '\t')
        i++;
    check_format(line + i,data,color);
}

int color_valid(char *s)
{
    if(!strcmp(s,"C"))
        return 0;
    if(!strcmp(s,"F"))
        return 0;
    return 1;
}

int     is_color(char *str)
{
    char **result = ft_split2(str);
    int i = 0;
    int type = 0;
    if(!color_valid(result[0]))
        type = 1;
    i = 0;
    while(result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
    return type;
}
int flor(char *s)
{
    if(strcmp(s,"F") == 0)
        return 1;
    return 0;
}
int ceiling(char *s)
{
    if(strcmp(s,"C") == 0)
        return 1;
    return 0;
}
int     color_type(char *s)
{   

    char **result = ft_split2(s);
    int i = 0;
    int type;
    if(ceiling(result[0]))
        type = 1;
    else if(flor(result[0]))
        type = 0;
    i = 0;
    while(result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
    return type;
}

void    check_colors(t_data_parsing      *data)
{
    int    i=0;
    int count = 0;
        
    while(i < 6)
    {
        if(is_color(data->map[i]))
        {
            check_flor(data->map[i],data,color_type(data->map[i]));
                count++;
        }
        i++;
    }
    if(count != 2)
    {
        printf("Invalid Colors\n");
        exit(1);
    }
}