#include "game.h"

t_map* get_map_info()
{
	static t_map info;
	return &info;
}

void create_map()
{
	t_map* info = get_map_info();
	
	strcpy_s(info->map[0], 11, "1111111111");
	strcpy_s(info->map[1], 11, "1000000001");
	strcpy_s(info->map[2], 11, "1010000111");
	strcpy_s(info->map[3], 11, "1010100001");
	strcpy_s(info->map[4], 11, "1010001001");
	strcpy_s(info->map[5], 11, "1000000001");
	strcpy_s(info->map[6], 11, "1000011001");
	strcpy_s(info->map[7], 11, "1010000001");
	strcpy_s(info->map[8], 11, "1010000001");
	strcpy_s(info->map[9], 11, "1111111111");

}

void draw_map()
{
	t_map* info = get_map_info();
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
		}
	}
}