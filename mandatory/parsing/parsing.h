/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:58 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/04 03:00:02 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "macros.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_data_parsing
{
	int			i;
	int			j;
	char		*north_txt;
	char		*south_txt;
	char		*west_txt;
	char		*east_txt;
	int			floor_color;
	int			ceiling_color;
	int			found_error;
	char		*error_msg;
	char		**map;
	char		**new_map;
	int			index_leaks;
	char		**leaks_task;
	int			player_x;
	int			player_y;
}				t_data_parsing;

typedef struct s_norminette
{
	char		*string;
	char		*liste;
	int			n;
	char		*line;
	char		**splited_map;
	int			i;
	char		**map;
	int			fd;
	int			coma;
	int			j;
	char		**split;

}				t_norminette;

typedef struct s_norm
{
	char		*line;
	int			count;
	char		**result;
	char		c;
	char const	*s;
	char		**split;
	char		*liste;
	int			start_cur;
	int			end_cur;
	int			i;
	int			fd;
}				t_norm;
typedef struct s_join
{
	int			i;
	int			len1;
	int			len2;
	char		*str;
	int			m;
	char		*s1;
	char		*s2;
}				t_join;

typedef struct t_split
{
	int			i;
	int			j;
	int			k;
	int			wc;
	char		**out;

}				t_split;

int				check_name(char *str);
void			check_vl(char *s);
void			check_different_digit(t_data_parsing *data);
int				count_lines(int fd, t_data_parsing *data);
char			**parse_map(char *str, t_data_parsing *data);
void			fill_map(char **map, int fd, t_data_parsing *data);
int				valid_line(char *line);
char			*ft_strjoin(char *s1, char *s2, t_data_parsing *data);
char			*gnl(int fd);
char			**ft_split(char const *s, char c, t_data_parsing *data);
void			check_text(t_data_parsing *data);
void			parse_fill(t_data_parsing *data);
char			**ft_split2(char *str);
char			**ft_split2_2(char *str);
void			check_colors(t_data_parsing *data);
void			check_map_game(t_data_parsing *data);
void			check_lfaraghat(char **map, t_data_parsing *data);
void			fill_spaces_with_walls(t_data_parsing *data);
void			parsing(t_data_parsing *data, char *map_name);
void			check_first_last(char *line);
void			check_player_duplicity(t_data_parsing *data);
void			check_valid_bit(char *line, int i, t_data_parsing *data,
					int color);
int				color_valid(char *s);
int				ceiling(char *s);
int				count_coma(char *line);
int				flor(char *s);
void			check_flor(char *line, t_data_parsing *data, int color);
int				ft_atoi(char *str);
void			check_format(char *line, t_data_parsing *data, int color);
void			check_err(char **map);
void			get_done4(t_norminette *norm, t_data_parsing *data);
void			get_done3(t_norminette *norm, t_data_parsing *data);
void			get_done2(t_norminette *norm, t_data_parsing *data);
void			get_done(t_norminette *norm, t_data_parsing *data);
void			init_norm(t_norminette *data);
void			init_sp2(t_split *sp2);
char			*ft_strncpy(char *s1, char *s2, int n);
void			add_text_to_struct(char *ident, char *line,
					t_data_parsing *data);
int				nbr_colone(char **map);
void			print_error(int a);
int				champ(char c);
int				count_bits(char *line);

#endif