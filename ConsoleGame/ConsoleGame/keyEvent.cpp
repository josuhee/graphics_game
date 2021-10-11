#include "game.h"

//normal key event
void processNormalKey(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		atexit(KillFont);
		exit(0);
	}
}

//special key event
void processSpcialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		printf("up\n");
		break;
	case GLUT_KEY_DOWN:
		printf("down\n");
		break;
	case GLUT_KEY_LEFT:
		printf("left\n");
		break;
	case GLUT_KEY_RIGHT:
		printf("right\n");
		break;
	}
}