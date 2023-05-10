#include "header.h"

int main()
{	
	t_player player;
	int array[MAP_NUM_ROWS][MAP_NUM_COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	for (int i = 0; i < 11; i++)
    	for (int j = 0; j < 15; j++)
    	    player.grid[i][j] = array[i][j];
	
    player.mlx_ptr = mlx_init();
	player.win_ptr = mlx_new_window(player.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

	render_map(&player);
	render_player(&player);
	update(&player);
	// mlx_hook(player.win_ptr, 2, 0, key_pressed, &player);
	// mlx_hook(player.win_ptr, 3, 0, key_released, &player);
	mlx_loop_hook(player.mlx_ptr, update, &player);
	mlx_loop(player.mlx_ptr);
}
