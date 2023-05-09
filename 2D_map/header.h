/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/09 18:04:12 by zanejar          ###   ########.fr       */
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
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

#define PIXEL 32
#define MAP_NUM_ROWS 11
#define MAP_NUM_COLS 15
#define WINDOW_WIDTH (MAP_NUM_COLS * PIXEL)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * PIXEL)
#define PI 3.14159265358979323846

typedef struct s_map
{
    int grid[MAP_NUM_ROWS][MAP_NUM_COLS];
} t_map;

typedef struct	s_player {
	float	x;
	float	y;
	float	radius;
	int	turnDirection;
	int	walkDirection;
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;
	float	height;
	float  width;
}				t_player;

#endif