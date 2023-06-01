/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/06/01 17:45:39 by zanejar          ###   ########.fr       */
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
# define FOV 60 * (PI / 180)

# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x000000
# define RED_COLOR 0xFF0000
# define GREEN_COLOR 0x00FFF0
# define BLUE_COLOR 0x0000FF
# define YELLOW_COLOR 0xFFFF00
# define PURPLE_COLOR 0x800080
# define WALLS_SKALE 2
# define ROSE_COLOR 0xFF00FF
# define GREY_COLOR 0x808080
# define BROWN_COLOR 0x964B00

# define PIXEL 32
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define PI 3.14159265358979323846

# define NBR_RAYS WINDOW_WIDTH
# define line_length 30
# define MINI_MAP_SCALE_FACTOR 0.2
# define WALL_STRIP_WIDTH 1

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

typedef struct s_ray
{
	double		x_intercept;
	double		y_intercept;
	double		x_step;
	double		y_step;
	double		next_vert_x;
	double		next_vert_y;
	double		next_horz_x;
	double		next_horz_y;
	double		hit_x_v;
	double		hit_y_v;
	int				found_door;
	double		hit_x_h;
	double		hit_y_h;
	double		hit_x;
	double		hit_y;
	double		dh;
	double		dv;
	double		ray_angle;
	double		ray_distance;
	int vert;
}				t_ray;

typedef struct s_img
{
	void		*img_ptr;
	int			*addr;
	int			bits_per_pixel;
	int			lineLength;
	int			endian;
}				t_img;

typedef struct s_wall
{
	double		strip_height;
	double		projection;
	double		perp_distance;
	int			strip_top;
	int			strip_bottom;
}				t_wall;

typedef struct s_player
{
	double		x;
	double		y;
	double		radius;
	int			walkDirection;
	int			sideDirection;
	double		rotationAngle;
	double		moveSpeed;
	double		rotationSpeed;
	double		height;
	double		width;
}				t_player;

typedef struct s_data
{
	void			**iimg;
	int				**grid;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_ray			ray[NBR_RAYS];
	t_img			texture[5];
	t_wall			wall;
	char			*door_path;
	long int		color_floor;
	int 			op;
	void			*img1_ptr;
	int 			m;
	int				n;
	int				wall_side;
	long int		color_ceiling;
	t_data_parsing	*parsing;
	t_player		player;
	int 			rows;
	int 			cols;
}				t_data;

void			render_map(t_data *data);
int 			update2(t_data *data) ;
void 			mlx_clear_image(t_data *data);
void 			direction(t_data *data);
int				close_window(void);
int				key_pressed(int keycode, t_data *data);
int				key_released(int keycode, t_data *data);
void			player_draw(t_data *data);
void			render_player(t_data *data, t_data_parsing *parsing);
int				update(t_data *data);
void			line_drawing(t_data *data, int end_x, int end_y);
void			ray_caster(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				able_to_walk_up(t_data *data);
int				able_to_walk_down(t_data *data);
int				able_to_turn_left(t_data *data);
int				able_to_turn_right(t_data *data);
double			adjust_angle(double angle);
int				found_Wall(t_data *data, int x, int y);
int				horizontal_intersection(t_data *data, int i);
int				vertical_intersection(t_data *data, int i);
void			cast_ray(t_data *data, int i);
double			distance_between_xy(t_data *data, double hit_x, double hit_y);
void			dist_calc(t_data *data, int i, int h, int v);

int				is_ray_facing_right(double my_angle);
int				is_ray_facing_down(double my_angle);

void			render_3d(t_data *data);
void			render_walls(t_data *data, int i);
int				calcul_rows(char **map);
int				calcul_col(char **map);
int				fill_int(char c);
void			open_door(t_data* data);

double			get_angle(t_data_parsing *data);

void textures_init(t_data *data);
void wall_sider(t_data *data, int i);
int	get_color(t_img *data, int x, int y);


#endif