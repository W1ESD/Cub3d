#include "header.h"

void render_map(t_player *player) 
{
    int x, y, color;
    for (int i = 0; i < MAP_NUM_ROWS; i++) {
        for (int j = 0; j < MAP_NUM_COLS; j++) {
            x = j * PIXEL;
            y = i * PIXEL;
            color = player->grid[i][j] == 1 ? 0x0FFFFF : 0x005FFF;
            for (int dx = 0; dx < PIXEL; dx++) {
                for (int dy = 0; dy < PIXEL; dy++) {
                    mlx_pixel_put(player->mlx_ptr, player->win_ptr, x + dx, y + dy, color);
                }
            }
        }
    }
}

void player_draw(t_player *player)
{
	int x, y, color;
	x = player->x;
	y = player->y;
	color = 0xFFFFFF;
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x + i, y + j, color);
		}
	}
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x - i, y - j, color);
		}
	}
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x - i, y + j, color);
		}
	}
	for (int i = 0; i < player->width; i++) {
		for (int j = 0; j < player->height; j++) {
			mlx_pixel_put(player->mlx_ptr, player->win_ptr, x + i, y - j, color);
		}
	}
	int line_length = 40;
	for(int i = 0; i < line_length; i++)
		mlx_pixel_put(player->mlx_ptr, player->win_ptr, x, y - i, color);
}

int key_pressed(int keycode, t_player *player)
{
	render_map(player);

    if (keycode == UP)
        (player->y)--;
    else if (keycode == DOWN)
        (player->y)++;
    else if (keycode == RIGHT)
        (player->x)++;
    else if (keycode == LEFT)
        (player->x)--;
	else 
	player_draw(player);
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

void render_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->width = 2.5;
	player->height = 2.5;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = PI / 2;
	player->moveSpeed = 5;
	player->rotationSpeed = 2 * (PI / 180);
	float x, y;
	int color;
	x = player->x;
	y = player->y;
	color = 0xFFFFFF;
	player_draw(player);
}



int	close_window(void)
{
	exit (0);
}

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
	for (int i = 0; i < 11; i++) {
    	for (int j = 0; j < 15; j++) {
    	    player.grid[i][j] = array[i][j];
    	}
}
    player.mlx_ptr = mlx_init();
	player.win_ptr = mlx_new_window(player.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	render_map(&player);
	render_player(&player);
	mlx_key_hook(player.win_ptr, key_pressed, &player);
	mlx_hook(player.win_ptr, 17, 0L, close_window, NULL);
	mlx_loop(player.mlx_ptr);
}
