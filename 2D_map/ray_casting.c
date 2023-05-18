
#include "header.h"

// void draw_line(t_player* player, int WallHitX, int WallHitY) {
//     int x0 = player->x;
//     int y0 = player->y;
//     int x1 = WallHitX;
//     int y1 = WallHitY;
    
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (x0 != x1 || y0 != y1) {
//         my_mlx_pixel_put(&player->img, x0, y0, WHITE_COLOR);
//         int err2 = 2 * err;
//         if (err2 > -dy) {
//             err -= dy;
//             x0 += sx;
//         }
//         if (err2 < dx) {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

void	 line_drawing(t_player* player,  int end_x, int end_y)
{
	int	pixels_color = WHITE_COLOR;

	float distance_x = end_x - player->x;
	float distance_y = end_y - player->y;

	int pixels = sqrt((distance_x * distance_x) + (distance_y * distance_y));

	distance_x /= pixels;
	distance_y /= pixels;


	float pixel_x = player->x;
	float pixel_y = player->y; 

    while (pixels > 0)
    {
        my_mlx_pixel_put(&player->img, pixel_x, pixel_y, pixels_color);
        pixel_x += distance_x;
        pixel_y += distance_y;
        pixels--;
    }
}
   
void	ray_caster(t_player*	player)
{
	float	ray_angle = player->rotationAngle - (FOV / 2);
	float	inc_angle = FOV / NBR_RAYS; 
	int i = 0;

	while(i < NBR_RAYS)
	{
		cast_ray(player, ray_angle);
		ray_angle += inc_angle;
		i++;
	}
}