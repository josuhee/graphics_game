#include "game.h"
#include "window.h"

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

	if (win->getMode() == 2)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			keyPress[2] = true;
			printf("up\n");
			break;
		case GLUT_KEY_DOWN:
			keyPress[3] = true;
			printf("down\n");
			break;
		case GLUT_KEY_LEFT:
			keyPress[0] = true;
			printf("left\n");
			break;
		case GLUT_KEY_RIGHT:
			keyPress[1] = true;
			printf("right\n");
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
			printf("up free\n");
			break;
		case GLUT_KEY_DOWN:
			keyPress[3] = false;
			printf("down free\n");
			break;
		case GLUT_KEY_LEFT:
			keyPress[0] = false;
			printf("left free\n");
			break;
		case GLUT_KEY_RIGHT:
			keyPress[1] = false;
			printf("right free\n");
			break;
		}
	}
	glutPostRedisplay();
}