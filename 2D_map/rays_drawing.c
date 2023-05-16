
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
        my_mlx_pixel_put(&player->img, pixel_x, pixel_y, pixels_color);
        pixel_x += distance_x;
        pixel_y += distance_y;
        --pixels;
    }
}
   
void	ray_draw(t_player*	player)
{
	int x;
	int y;
	
	x = player->x;
	y = player->y;
	double	my_angle = player->rotationAngle - FOV / 2; 
	int i = NBR_RAYS;

	//-> ___my_angle will be increased with (FOV / WINDOW_WIDTH) (bach tkon wahd small angle bin ray w ray ghanhtajha bach nrsm kola line)
	//-> ___i will be decreased to draw total of NBR_RAYS rays = WINDOW_WIDTH;

	while(i)
	{
		cast_ray(player,my_angle);
		my_angle += FOV / WINDOW_WIDTH;
		i--;
	}
}