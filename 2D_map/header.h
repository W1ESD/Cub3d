/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:48 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/09 05:40:53 by zanejar          ###   ########.fr       */
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
# define UP 13
# define LEFT 0
# define DOWN 1 
# define RIGHT 2 

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
	double	x;
	double	y;
	double	radius;
	double	turnDirection;
	double	walkDirection;
	double	rotationAngle;
	double	moveSpeed;
	double	rotationSpeed;
	double	height;
	double  width;
}				t_player;

#endif