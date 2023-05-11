#include "header.h"


void	 line_drawing(t_player* player,  int end_x, int end_y)
{
	int	pixels_color = WHITE_COLOR;



	double distance_x = end_x - player->x;
	double distance_y = end_y - player->y;


	int pixels = sqrt((distance_x * distance_x) + (distance_y * distance_y));


	distance_x /= pixels;
	distance_y /= pixels;


	double pixel_x = player->x;
	double pixel_y = player->y;



    while (pixels)
    {
        mlx_pixel_put(player->mlx_ptr, player->win_ptr, pixel_x, pixel_y, pixels_color);
        pixel_x += distance_x;
        pixel_y += distance_y;
        --pixels;
    }

}