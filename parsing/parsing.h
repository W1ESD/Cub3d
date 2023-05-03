#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>


#define    NAME_ERROR      "\033[91;1mError \nIncorrect file name \033[0m"
#define    FILE_NOT_FOUND  "\033[91;1mError \nfile not found \033[0m"
#define    LMAP   "\033[91;1mError \nNew Line In Map\033[0m"


int             check_name(char *str);
char**          parse_map(char *str);
char*           gnl(int fd);
void    fill_map(char   **map,int fd);
void    fill_map2d(char     **map,int   fd);
int     empty_line(char *str);
int     count_lines(int fd);