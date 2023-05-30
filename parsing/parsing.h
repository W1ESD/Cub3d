/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:58 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/30 16:02:45 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
#define PARS_H



#include <fcntl.h>
#include <sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>
#include "macros.h"

typedef struct s_list t_list;

typedef struct s_list
{
    char    *string;
    t_list  *next; 
}t_list;

typedef struct s_data_parsing
{
	int i;
	int j;
    char        *north_txt; 
    char        *south_txt;
    char        *west_txt; 
    char        *east_txt;
    int         floor_color;
    int         ceiling_color;
    int         found_error;
    char        *error_msg;
    char        **map;
    char        **new_map;
    int         index_leaks;
    char        **leaks_task;
    int         player_x;
    int         player_y;
}t_data_parsing; 



int             check_name(char *str);
int             count_lines(int fd,t_data_parsing* data);
char**          parse_map(char *str,t_data_parsing *data);
void            fill_map(char   **map,int fd,t_data_parsing *data);
int             valid_line(char *line);
char	        *ft_strjoin(char  *s1, char  *s2,t_data_parsing* data);
char*            gnl(int fd);
char	        **ft_split(char const *s, char c,t_data_parsing* data);
void            check_text(t_data_parsing* data);
void            parse_fill(t_data_parsing* data);
char	        **ft_split2(char *str);
char	        **ft_split2_2(char *str);
void            check_colors(t_data_parsing      *data);
void            check_map_game(t_data_parsing *data);
void            check_lfaraghat(char    **map,t_data_parsing    *data);
void            fill_spaces_with_walls(t_data_parsing* data);
void            parsing(t_data_parsing  *data,char  *map_name);




#endif