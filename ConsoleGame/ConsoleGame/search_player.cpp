#include "game.h"
#include "window.h"
#include <queue>

int arr[10][10];

// init array
static void init_arr()
{
	Window* win = Window::getInstance();
	t_map* info = get_map_info();

	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (info->map[i][j] == '1') arr[i][j] = -1;
}

// search player, use bfs algorithm
pair<int, int> search_player()
{
	init_arr();

	t_map* info = get_map_info();
	queue <pair<int, int>> q;
	q.push({ info->player_x, info->player_y });
	arr[info->player_y][info->player_x] = 1;

	bool flag = false;
	int x, y, nx, ny;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,-1,1 };
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx == info->enemy_x && ny == info->enemy_y)
			{
				flag = true;
				break;
			}

			if (nx >= 0 && ny >= 0 && nx < 10 && ny < 10 && arr[ny][nx] == 0)
			{
				arr[ny][nx] = arr[y][x] + 1;
				q.push({ nx,ny });
			}
		}
		if (flag) break;
	}
	return { x, y };
}