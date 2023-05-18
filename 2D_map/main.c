#include "header.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->lineLength + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{	
	t_player player;
	int array[MAP_NUM_ROWS][MAP_NUM_COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	for (int i = 0; i < MAP_NUM_ROWS; i++)
    	for (int j = 0; j < MAP_NUM_COLS; j++)
    	    player.grid[i][j] = array[i][j];
	
    player.mlx_ptr = mlx_init();
	player.win_ptr = mlx_new_window(player.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub_2d");

	player.img.img_ptr = mlx_new_image(player.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	player.img.addr = mlx_get_data_addr(player.img.img_ptr, &player.img.bits_per_pixel, &player.img.lineLength, &player.img.endian);
	
	render_map(&player);
	render_player(&player);
	update(&player);
	mlx_hook(player.win_ptr, 2, 0, key_pressed, &player);
	mlx_hook(player.win_ptr, 3, 0, key_released, &player);
	mlx_loop_hook(player.mlx_ptr, update, &player);
	mlx_loop(player.mlx_ptr);
}
