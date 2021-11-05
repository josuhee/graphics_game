#include "game.h"
#include "window.h"

bool mvFlag = true;
float dx = 0.0f, dy = 0.0f;

static void checkItem(int x, int y)
{
	t_map* info = get_map_info();

	if (info->map[y][x] == 'C')
		info->item_cnt -= 1;
	if (info->item_cnt == 0)
	{
		info->item_cnt = -1;
		int i, j;
		while (1)
		{
			i = rand() % 8 + 1;
			j = rand() % 8 + 1;
			if (info->map[i][j] == '0')
			{
				info->map[i][j] = 'E';
				break;
			}
		}
	}
}

static void checkExit(int x, int y)
{
	Window* win = Window::getInstance();
	t_map* info = get_map_info();

	if (info->map[y][x] != 'E') return;

	//game clear
	printf("game clear\n");
	win->setMode(3);
	info->clear = true;
}

static void checkEnemy(int x, int y)
{
	Window* win = Window::getInstance();
	t_map* info = get_map_info();

	if (info->enemy_x == info->player_x && info->enemy_y == info->player_y)
	{
		//game over
		printf("game over\n");
		win->setMode(3);
	}
}

void upTimer(int v)
{
	t_map* info = get_map_info();

	int x = info->player_x;
	int y = info->player_y;

	if (v == 5) {
		checkItem(x, y - 1);
		checkExit(x, y - 1);
		checkEnemy(x, y - 1);
		dx = dy = 0.0f;
		info->map[y][x] = '0';
		info->map[y - 1][x] = 'P';
		info->player_y = y - 1;
		mvFlag = true;
		return;
	}
	dy = 0.04f * v;
	mvFlag = false;
	glutPostRedisplay();
	//printf("%d\n", v);
	glutTimerFunc(40, upTimer, v+1);
}

void downTimer(int v)
{
	t_map* info = get_map_info();

	int x = info->player_x;
	int y = info->player_y;

	if (v == 5) {
		checkItem(x, y + 1);
		checkExit(x, y + 1);
		checkEnemy(x, y + 1);
		dx = dy = 0.0f;
		info->map[y][x] = '0';
		info->map[y + 1][x] = 'P';
		info->player_y = y + 1;
		mvFlag = true;
		return;
	}
	mvFlag = false;
	dy = -0.04f * v;
	glutPostRedisplay();
	glutTimerFunc(40, downTimer, v + 1);
}

void leftTimer(int v)
{
	t_map* info = get_map_info();

	int x = info->player_x;
	int y = info->player_y;

	if (v == 5) {
		checkItem(x - 1, y);
		checkExit(x - 1, y);
		checkEnemy(x - 1, y);
		dx = dy = 0.0f;
		info->map[y][x] = '0';
		info->map[y][x - 1] = 'P';
		info->player_x = x - 1;
		mvFlag = true;
		return;
	}
	mvFlag = false;
	dx = -0.04f * v;
	glutPostRedisplay();
	glutTimerFunc(40, leftTimer, v + 1);
}

void rightTimer(int v)
{
	t_map* info = get_map_info();

	int x = info->player_x;
	int y = info->player_y;

	if (v == 5) {
		checkItem(x + 1, y);
		checkExit(x + 1, y);
		checkEnemy(x + 1, y);
		dx = dy = 0.0f;
		info->map[y][x] = '0';
		info->map[y][x + 1] = 'P';
		info->player_x = x + 1;
		mvFlag = true;
		return;
	}
	mvFlag = false;
	dx = 0.04f * v;
	glutPostRedisplay();
	glutTimerFunc(40, rightTimer, v + 1);
}

void move_player(int num, int x, int y)
{
	if (!(x >= 0 && y >= 0 && x < 10 && y < 10)) return;

	t_map* info = get_map_info();

	if (mvFlag)
	{
		//move
		if (info->map[y][x] != '1')
		{
			if (num == 0) glutTimerFunc(0, leftTimer, 1);
			if (num == 1) glutTimerFunc(0, rightTimer, 1);
			if (num == 2) glutTimerFunc(0, upTimer, 1);
			if (num == 3) glutTimerFunc(0, downTimer, 1);
		}
	}
}

//normal key event
void processNormalKey(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		printf("\033[32mExit the Game\033[0m\n");
		exit(0);
	}
}

extern bool keyPress[4];

//special key event
void processSpcialKey(int key, int x, int y)
{
	Window* win = Window::getInstance();
	t_map* info = get_map_info();

	if (win->getMode() == 2)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			move_player(2, info->player_x, info->player_y - 1);
			keyPress[2] = true;
			break;
		case GLUT_KEY_DOWN:
			move_player(3, info->player_x, info->player_y +1);
			keyPress[3] = true;
			break;
		case GLUT_KEY_LEFT:
			move_player(0, info->player_x - 1, info->player_y);
			keyPress[0] = true;
			break;
		case GLUT_KEY_RIGHT:
			move_player(1, info->player_x + 1, info->player_y);
			keyPress[1] = true;
			break;
		}
	}
	glutPostRedisplay();
}

void processSpecialKeyUp(int key, int x, int y)
{
	Window* win = Window::getInstance();

	if (win->getMode() == 2)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			keyPress[2] = false;
			break;
		case GLUT_KEY_DOWN:
			keyPress[3] = false;
			break;
		case GLUT_KEY_LEFT:
			keyPress[0] = false;
			break;
		case GLUT_KEY_RIGHT:
			keyPress[1] = false;
			break;
		}
	}
	glutPostRedisplay();
}