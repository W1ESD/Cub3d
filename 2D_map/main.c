#include "header.h"

void render_map(t_map *map, void *mlx_ptr, void *win_ptr) 
{
    int x, y, color;
    for (int i = 0; i < MAP_NUM_ROWS; i++) {
        for (int j = 0; j < MAP_NUM_COLS; j++) {
            x = j * PIXEL;
            y = i * PIXEL;
            color = map->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            for (int dx = 0; dx < PIXEL; dx++) {
                for (int dy = 0; dy < PIXEL; dy++) {
                    mlx_pixel_put(mlx_ptr, win_ptr, x + dx, y + dy, color);
                }
            }
        }
    }
}

int key_pressed(int keycode, t_player *player)
{
    if (keycode == UP)
        player->walkDirection = 1;
    else if (keycode == DOWN)
        player->walkDirection = -1;
    else if (keycode == RIGHT)
        player->turnDirection = 1;
    else if (keycode == LEFT)
        player->turnDirection = -1;
    return (0);
}

int key_released(int keycode, t_player *player)
{
    if (keycode == UP || keycode == DOWN)
        player->walkDirection = 0;
    else if (keycode == RIGHT || keycode == LEFT)
        player->turnDirection = 0;
    return (0);
}

void render_player(void *mlx_ptr, void *win_ptr, t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->width = 5;
	player->height = 5;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = PI / 2;
	player->moveSpeed = 5;
	player->rotationSpeed = 2 * (PI / 180);
	int x, y, color;
	x = player->x;
	y = player->y;
	color = 0xFFFFFF;
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(mlx_ptr, win_ptr, (x - 2) + i, (y - 2) + j, color);
		}
	}
	int line_length = 40;
	for(int i = 0; i < line_length; i++)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y - i, color);
}

int	close_window(void)
{
	exit (0);
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
	t_player player;
	render_player( mlx_ptr, win_ptr, &player);
	mlx_key_hook(win_ptr, key_pressed, &player);
	mlx_hook(win_ptr, 17, 0L, close_window, NULL);
	mlx_loop(mlx_ptr);
}
