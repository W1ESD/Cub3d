#include "header.h"

void render_map(t_map *map, void *mlx_ptr, void *win_ptr) 
{
    int x, y, color;
    for (int i = 0; i < MAP_NUM_ROWS; i++) {
        for (int j = 0; j < MAP_NUM_COLS; j++) {
            x = j * PIXEL;
            y = i * PIXEL;
            color = map->grid[i][j] == 1 ? 0xFFFFFF : 0x000000;
            for (int dx = 0; dx < PIXEL; dx++) {
                for (int dy = 0; dy < PIXEL; dy++) {
                    mlx_pixel_put(mlx_ptr, win_ptr, x + dx, y + dy, color);
                }
            }
        }
    }
}

void render_player(void *mlx_ptr, void *win_ptr)
{
	t_player player;
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.width = 5;
	player.height = 5;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = PI / 2;
	player.moveSpeed = 5;
	player.rotationSpeed = 2 * (PI / 180);
	int x, y, color;
	x = player.x;
	y = player.y;
	color = 0xFF0000;
	for (int i = 0; i < player.width; i++) {
		for (int j = 0; j < player.height; j++) {
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
		}
	}
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    t_map map = {
        {
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
        }
    };
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	render_map(&map, mlx_ptr, win_ptr);
	render_player( mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}
