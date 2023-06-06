/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/06 03:57:34 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef PARSER
#  define PARSER

#  include "../parsing/macros.h"
#  include "../parsing/parsing.h"

# endif
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

# define ESC 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x000000
# define RED_COLOR 0xFF0000
# define LINE_LENGTH 50
# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define PI 3.14159265358979323846
# define NBR_RAYS WINDOW_WIDTH
# define MINI_MAP_SCALE_FACTOR 0.4
# define WALL_STRIP_WIDTH 1
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define DOOR 4
# define TEX_SIZE 64

typedef struct s_ray
{
	double			x_intercept;
	double			y_intercept;
	double			x_step;
	double			y_step;
	double			next_vert_x;
	double			next_vert_y;
	double			next_horz_x;
	double			next_horz_y;
	double			hit_x_v;
	double			hit_y_v;
	int				found_door;
	double			hit_x_h;
	double			hit_y_h;
	int				hit_door_vertical;
	int				hit_door_horizontal;
	double			hit_x;
	double			hit_y;
	double			dh;
	double			dv;
	double			ray_angle;
	double			ray_distance;
	int				vert;
}					t_ray;

typedef struct s_img
{
	void			*img_ptr;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_wall
{
	double			strip_height;
	double			projection;
	double			perp_distance;
	int				strip_top;
	int				strip_bottom;
}					t_wall;

typedef struct s_player
{
	double			x;
	double			y;
	double			radius;
	int				walk_direction;
	int				side_direction;
	double			rotation_angle;
	double			move_speed;
	double			rotation_speed;
	double			height;
	double			width;
}					t_player;

typedef struct s_vars
{
	int				x;
	int				y;
	int				color;
	int				i;
	int				j;
	int				dx;
	int				dy;
	int				pixels_color;
	double			distance_x;
	double			distance_y;
	int				pixels;
	double			pixel_x;
	double			pixel_y;
}					t_vars;

typedef struct s_data
{
	void			**iimg;
	int				**grid;
	void			*mlx_ptr;
	void			*win_ptr;
	double			tile_size;
	t_img			img;
	t_ray			ray[NBR_RAYS];
	t_img			texture[5];
	int				**text_leak;
	t_wall			wall;
	char			*door_path;
	long int		color_floor;
	int				op;
	double			pixel_x;
	double			pixel_y;
	int				x_door;
	int				y_door;
	void			*img1_ptr;
	int				m;
	int				n;
	int				wall_side;
	long int		color_ceiling;
	t_data_parsing	*parsing;
	t_player		player;
	int				rows;
	int				cols;
}					t_data;

void				render_map(t_data *data);
int					update2(t_data *data);
void				direction(t_data *data);
int					close_window(void);
int					key_pressed(int keycode, t_data *data);
int					key_released(int keycode, t_data *data);
void				player_draw(t_data *data);
void				render_player(t_data *data, t_data_parsing *parsing);
int					update(t_data *data);
void				line_drawing(t_data *data, int end_x, int end_y);
void				ray_caster(t_data *data);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
int					able_to_walk_up(t_data *data);
int					able_to_walk_down(t_data *data);
int					able_to_turn_left(t_data *data);
int					able_to_turn_right(t_data *data);
double				adjust_angle(double angle);
int					horizontal_intersection(t_data *data, int i);
int					vertical_intersection(t_data *data, int i);
void				cast_ray(t_data *data, int i);
double				distance_between_xy(t_data *data, double hit_x,
						double hit_y);
void				dist_calc(t_data *data, int i, int h, int v);
int					is_ray_facing_right(double my_angle);
int					is_ray_facing_down(double my_angle);
void				render_3d(t_data *data);
void				render_walls(t_data *data, int i);
int					calcul_rows(char **map);
int					calcul_col(char **map);
int					really_able_up(t_data *data);
int					fill_int(char c);
void				open_door(t_data *data);
double				get_angle(t_data_parsing *data);
void				textures_init(t_data *data);
void				wall_sider(t_data *data, int i);
int					get_color(t_img *data, int x, int y);
int					func(int x, int y, void *param);
char				**ft_add_map(int fd, t_data_parsing *data_parsing);
void				func_picture(t_data *data, t_data_parsing *data_parsing);
double				adjust_angle(double angle);
int					found_wall(t_data *data, int x, int y);
int					to_door(t_data *data, int x, int y);
int					is_ray_facing_down(double my_angle);
int					is_ray_facing_right(double my_angle);
int					really_able(t_data *data, int ind);
void				direction(t_data *data);
void				render_animation(t_data *data);
int					update(t_data *data);
int					really_able_right(t_data *data);
int					really_able_left(t_data *data);
void				render_walls(t_data *data, int i);
void				wall_collision_gliss(t_data *data);
void				wall_col_ray_h(t_data *data, int index, int i);
void				wall_col_ray_v(t_data *data, int index, int i);
void				set_hit1(t_data *data, int i);
void				set_hit2(t_data *data, int i);
void				set_hit3(t_data *data, int i);
int					really_able_down(t_data *data);
int					really_able_up(t_data *data);
int					wall_y(t_data *data);
int					wall_x(t_data *data);
void				cond1(t_data *data);
void				cond2(t_data *data);
void				cond3(t_data *data);
void				cond4(t_data *data);
int					wall_x_left(t_data *data);
int					wall_y_left(t_data *data);
int					wall_x_right(t_data *data);
int					wall_y_right(t_data *data);
int					wall_x_down(t_data *data);
int					wall_y_down(t_data *data);

#endif