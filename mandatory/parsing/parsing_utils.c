/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:44 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/31 12:09:04 by zanejar          ###   ########.fr       */
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


int     count_lines(int fd)
{
    int count = 0;
    char    *line;

    line = gnl(fd);
    while(line)
    {
        count++;
        // free(line);
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