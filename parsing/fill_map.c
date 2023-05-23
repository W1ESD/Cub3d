/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:50:55 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/23 08:40:37 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


void    follow_to_map(char  **map,int   fd)
{
    char    *line = gnl(fd);
    char    *liste = NULL;
    int     n;
    int         i = 6;

    map[6] = NULL;
    if(line)
        n = valid_line(line);
    while(line && !n)
    {
        free(line);
        line = gnl(fd);
        if(line)
            n = valid_line(line);
    }
    while(1)
    {
        if(!line)
            break;
        liste = ft_strjoin(liste, line);
        free(line);
        line = gnl(fd);
        if(line)
            n = valid_line(line);
        if(!n || !line)
            break;
    }
    while(line && !n)
    {
        free(line);
        line = gnl(fd);
        if(line)
            n = valid_line(line);
    }
    if(line && n)
    {
        free(line);
        printf("%s%s\n",ERROR,"Map Line Error \033[0m");
        exit(0);
    }
    char    **splited_map=NULL;
    if(liste)
        splited_map = ft_split(liste,'\n');
    free(liste);
    int     j = 0;
    if(splited_map){
    while(splited_map[j])
    {       
        map[i] = splited_map[j];
        i++;
        j++;
    }}
    map[i] = NULL;
    if(!map[6])
    {
        printf("%s%s\n",ERROR,"Incomplete Map \033[0m");
        exit(0);
    }
    free(splited_map);
}

void    fill_map(char   **map,int fd,t_data_parsing *data)
{
   char     *line;
   int      count = 0;
   char     *liste;
   char     **split;
   int      i = 0;
   
   line = gnl(fd);
   while (line)
   {    
        if(valid_line(line))
        {
            liste = ft_strjoin(liste,line);
            count++;
        }
        free(line);
        if(count >= 6)
            break;
        line = gnl(fd);
   }
   split = ft_split(liste,'\n');
   free(liste);
   if(count < 6)
   {
        data->error_msg = "Incomplete Map\033[0m\n";
        printf("%s%s",ERROR,data->error_msg);
        exit(1);
   }
   
   while (split[i])
   {
        map[i] = split[i];
        i++;
   }
   free(split);
   follow_to_map(map,fd);
   data->map = map;
}
