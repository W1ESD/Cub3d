
#include "header.h"

void	 line_drawing(t_data *data,  int end_x, int end_y)
{
	int	pixels_color = WHITE_COLOR;

	float distance_x = end_x - data->player.x;
	float distance_y = end_y - data->player.y;

	int pixels = sqrt((distance_x * distance_x) + (distance_y * distance_y));

	distance_x /= pixels;
	distance_y /= pixels;

	float pixel_x = data->player.x;
	float pixel_y = data->player.y; 

    while (pixels > 0)
    {
        my_mlx_pixel_put(&data->img, pixel_x * MINI_MAP_SCALE_FACTOR,\
		pixel_y * MINI_MAP_SCALE_FACTOR, pixels_color);
        pixel_x += distance_x;
        pixel_y += distance_y;
        pixels--;
    }
}

void	ray_caster(t_data *data)
{
	data->wall.proj = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	// float	inc_angle = FOV / NBR_RAYS; 
	// data->ray[i].ray_angle = data->ray[i].rotationAngle - (FOV / 2);
	int i = 0;

	while(i < NBR_RAYS)
	{
		data->ray[i].ray_angle = data->player.rotationAngle + atan((i - NBR_RAYS / 2) / data->wall.proj);
		cast_ray(data, i);
		// player->ray.ray_angle += inc_angle;
		i++;
	}
}