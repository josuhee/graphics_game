#include "game.h"
#include "window.h"
#include <time.h>

//Singleton Model
t_map*	get_map_info()
{
	static t_map info;
	return &info;
}

//Map Init
void		create_map()
{
	srand((unsigned int)time(NULL));
	t_map* info = get_map_info();
	info->clear = false;

	strcpy_s(info->map[0], 11, "1111111111");
	strcpy_s(info->map[1], 11, "10000000A1");
	strcpy_s(info->map[2], 11, "1010000111");
	strcpy_s(info->map[3], 11, "1000100001");
	strcpy_s(info->map[4], 11, "1110001001");
	strcpy_s(info->map[5], 11, "1000000001");
	strcpy_s(info->map[6], 11, "1010011001");
	strcpy_s(info->map[7], 11, "1010000001");
	strcpy_s(info->map[8], 11, "1P00000001");
	strcpy_s(info->map[9], 11, "1111111111");

	//random location item
	info->item_cnt = rand() % 5 + 3;
	int x, y;
	for (int i = 0; i < info->item_cnt; i++)
	{
		while (1)
		{
			x = rand() % 8 + 1; //1 ~ 8
			y = rand() % 8 + 1; // 1 ~ 8
			if (info->map[x][y] == '0')
			{
				info->map[x][y] = 'C';
				break;
			}
		}
	}
	info->map[1][8] = '0';
	info->enemy_x = 8;
	info->enemy_y = 1;
}

//origin at gamePage.cpp
extern int	player_idx;
extern int	item_idx;
extern int	enemy_idx;

//origin at keyEvent.cpp
extern float	dx, dy;
extern float e_dx, e_dy;

//paint map
void draw_map()
{
	Window* win = Window::getInstance();
	t_map* info = get_map_info();
	t_point_f player[2] = { {0.0f,0.0f},{0.0f,0.0f} };
	float nx, ny;

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//wall
			if (info->map[y][x] == '1')
			{
				nx = x * 0.2f - 1.0f;
				ny = 1.0f - y * 0.2f;
				draw_img(0, { nx, ny - 0.2f }, { nx + 0.2f, ny });
			}
			//player
			if (info->map[y][x] == 'P')
			{
				info->player_x = x;
				info->player_y = y;
				nx = x * 0.2f - 1.0f;
				ny = 1.0f - y * 0.2f;
				player[0] = { nx + dx, ny - 0.2f + dy };
				player[1] = { nx + 0.2f + dx, ny + dy };
				draw_img_player(player_idx, { nx + dx, ny - 0.2f + dy}, { nx + 0.2f + dx, ny + dy});
			}
			//item
			if (info->map[y][x] == 'C')
			{
				nx = x * 0.2f - 1.0f;
				ny = 1.0f - y * 0.2f;
				draw_img_item(item_idx, { nx + 0.05f, ny - 0.2f + 0.05f }, { nx + 0.2f - 0.05f, ny - 0.05f });
			}
			//exit
			if (info->map[y][x] == 'E')
			{
				nx = x * 0.2f - 1.0f;
				ny = 1.0f - y * 0.2f;
				draw_img(1, { nx, ny - 0.2f }, { nx + 0.2f, ny });
			}
		}
	}
	//enemy
	nx = info->enemy_x * 0.2f - 1.0f;
	ny = 1.0f - info->enemy_y * 0.2f;
	draw_img_enemy(enemy_idx, { nx + e_dx, ny - 0.2f + e_dy }, { nx + 0.2f + e_dx, ny + e_dy });

	//∏∂¡÷√∆¿ª ∂ß,,,
	t_point_f enemy[2];
	enemy[0] = { nx + e_dx, ny - 0.2f + e_dy };
	enemy[1] = { nx + 0.2f + e_dx, ny + e_dy };

	//¡¬øÏ
	if ((player[0].x < enemy[0].x && enemy[0].x < player[1].x) || (player[0].x < enemy[1].x && enemy[1].x < player[1].x))
	{
		if (player[0].y == enemy[0].y && player[1].y == enemy[1].y)
		{
			win->setMode(3);
		}
	}

	//ªÛ«œ
	if ((player[0].y < enemy[0].y && enemy[0].y < player[1].y) || (player[0].y < enemy[1].y && enemy[1].y < player[1].y))
	{
		if (player[0].x == enemy[0].x && player[1].x == enemy[1].x)
		{
			win->setMode(3);
		}
	}
	
}