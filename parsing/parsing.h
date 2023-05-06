#ifndef PARSING_H
#define PARSING_H



#include <fcntl.h>
#include <sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>
#include "macros.h"


typedef struct s_data
{
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
}t_data;


int             check_name(char *str,t_data *data);
int             count_lines(int fd);
char**          parse_map(char *str,t_data *data);
void            fill_map(char   **map,int fd,t_data *data);
int             valid_line(char *line);
char	        *ft_strjoin(char  *s1, char  *s2);
char*           gnl(int fd);
char	        **ft_split(char const *s, char c);
void            check_text(t_data* data);
void            parse_fill(t_data* data);
char	        **ft_split2(char *str);
char	        **ft_split2_2(char *str);
void            check_colors(t_data      *data);
void            check_map_game(t_data *data);
void            check_lfaraghat(char    **map,t_data    *data);

#endif