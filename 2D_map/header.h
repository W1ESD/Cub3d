 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/11 17:55:49 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include<mlx.h>

# define ESC 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define FOV  60 * (PI / 180)

#define WHITE_COLOR  0xFFFFFF
#define PIXEL 32
#define MAP_NUM_ROWS 11
#define MAP_NUM_COLS 15
#define WINDOW_WIDTH (MAP_NUM_COLS * PIXEL)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * PIXEL)
#define PI 3.14159265358979323846

#define NBR_RAYS WINDOW_WIDTH
#define line_length  30


typedef struct s_ray
{
	long	x_intercept;
    long	y_intercept;
    long	x_step;
    long	y_step;
    long	next_x;
    long	next_y;
}				t_ray;

typedef struct s_hit
{
	float hit_x_v;
	float hit_y_v;
	float hit_x_h;
	float hit_y_h;
	float hit_x;
	float hit_y;
	float dh;
    float dv;
}				t_hit;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		lineLength;
	int		endian;
}				t_img;

typedef struct	s_player {
	float	x;
	float	y;  
	float	radius;
	int		walkDirection;
	int 	sideDirection;
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;
	float	height;
	float   width;
	void	*mlx_ptr;
	void	*win_ptr;
	int 	grid[MAP_NUM_ROWS][MAP_NUM_COLS];
	t_img	img;
	t_ray	ray;
	t_hit	hit;
	float	hit_distance;
}				t_player;

void			render_map(t_player *player);
int				close_window(void);
int				key_pressed(int keycode, t_player *player);
int				key_released(int keycode, t_player *player);
void			player_draw(t_player *player);
void			render_player(t_player *player);
int				update(t_player *player) ;
void	 		line_drawing(t_player* player,  int end_x, int end_y);
void			ray_caster(t_player*	player);
void    		cast_ray(t_player*  player,float my_angle);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				able_to_walk_up(t_player* player);
int				able_to_walk_down(t_player* player);
int				able_to_turn_left(t_player* player);
int				able_to_turn_right(t_player* player);
float			adjust_angle(float angle);
int				found_Wall(int x,int y,t_player *player);
void			horizontal_intersection(t_player* player,float my_angle);
void			vertical_intersection(t_player* player,float my_angle);
void			cast_ray(t_player*  player,float my_angle);
float			distance_between_xy(t_player* player,float *hit_x,float *hit_y);
void			dist_cacl(t_player*  player);
void			draw_line(t_player* player, int WallHitX, int WallHitY);

int is_ray_facing_right(float my_angle);
int is_ray_facing_down(float my_angle);


#endif