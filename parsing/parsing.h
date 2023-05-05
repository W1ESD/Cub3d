#include <fcntl.h>
#include <sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>


#define         NAME_ERROR      "\033[91;1mError \nIncorrect file name \033[0m"
#define         FILE_NOT_FOUND  "\033[91;1mError \nfile not found \033[0m"
#define         LMAP            "\033[91;1mError \nNew Line In Map\033[0m"


int         check_name(char *str);
int         count_lines(int fd);
char*       gnl(int fd);
char**      parse_map(char *str);
void        fill_map(char   **map,int fd);
char	    *ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char	    **ft_split2(char *str);
void        parse_fill(char    **map);
char	    **ft_split2_2(char *str);
int	        ft_atoi(char *str);
void    encoutourd_map(char **map);
void    check_lfaraghat(char    **map); 