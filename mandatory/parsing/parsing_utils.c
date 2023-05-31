/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:44 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/28 23:08:54 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"
    

int check_name(char *str)
{   
    int  i = -1;
    

    while(str[++i]);
    
    i--;

    if(str[i] == 'b' && str[i-1] == 'u' && str[i-2] == 'c' && str[i-3] == '.')
        return 0;
    else
    {
        printf("%s",ERROR);
        printf("Wrong Extention File \n");
        exit(1);
    } 
}


int     count_lines(int fd,t_data_parsing *data)
{
    int count = 0;
    char    *line;

    line = gnl(fd);
    while(line)
    {
        count++;
        data->leaks_task[data->index_leaks++] = line;
        // (line);
        line = gnl(fd);
    }
    close(fd);
    return(count);
}

int     valid_line(char *line)
{
    int     i = 0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\n')
            return(1);
        i++;
    }
    return(0);
}
