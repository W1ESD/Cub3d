/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/10 17:47:35 by zanejar          ###   ########.fr       */
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

#define PIXEL 32
#define MAP_NUM_ROWS 11
#define MAP_NUM_COLS 15
#define WINDOW_WIDTH (MAP_NUM_COLS * PIXEL)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * PIXEL)
#define PI 3.14159265358979323846

// typedef struct s_map
// {
//     int grid[MAP_NUM_ROWS][MAP_NUM_COLS];
// } t_map;

typedef struct	s_player {
	float	x;
	float	y;
	float	radius;
	// int		turnDirection;
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
}				t_player;

void	render_map(t_player *player);
int		close_window(void);
int		key_pressed(int keycode, t_player *player);
int		key_released(int keycode, t_player *player);
void	player_draw(t_player *player);
void	render_player(t_player *player);
int	update(t_player *player) ;

#endif